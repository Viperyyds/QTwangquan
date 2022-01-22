#include "serverwidget.h"
#include "ui_serverwidget.h"
#include<QFileDialog>
#include<QFileInfo>
#include<QTimer>

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);


    tcpserver = NULL;
    tcpsocket = NULL;


    tcpserver = new QTcpServer(this);
    tcpserver->listen(QHostAddress::Any,8888);
    setWindowTitle("服务器：8888");

    ui->buttonfile->setEnabled(false);//按键变灰
    ui->send->setEnabled(false);



    connect(tcpserver, &QTcpServer::newConnection,
            [=]()
            {
        tcpsocket = tcpserver->nextPendingConnection();
        QString ip = tcpsocket->peerAddress().toString();
        qint16 port = tcpsocket->peerPort();
        QString temp = QString("[%1%2]:成功连接").arg(ip).arg(port);
        ui->read->setText(temp);

        ui->buttonfile->setEnabled(true);

        connect(tcpsocket,&QTcpSocket::readyRead,
                [=]()
        {
           QByteArray array = tcpsocket->readAll();
           ui->read->append(array);
        });

            });
    connect(&timer,&QTimer::timeout,
            [=]()
    {
        timer.stop();
        senddata();
    });


}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_pushButton_clicked()
{
    if(NULL == tcpsocket)
    {
        return;
    }
    QString str = ui->write->toPlainText();
    tcpsocket->write(str.toUtf8().data());
    //ui->read->setText("客户端");
    ui->read->append(str);
    ui->write->clear();
}


void ServerWidget::on_pushButton_2_clicked()
{
    if(NULL == tcpsocket)
    {
        return;
    }
    tcpsocket->disconnectFromHost();
    tcpsocket->close();
    tcpsocket = NULL;
}


void ServerWidget::on_pushButton_3_clicked()
{
    ui->read->clear();
}

void ServerWidget::senddata()
{
    qint64 len = 0 ;
    do
    {
        char buf[4*1024] ={0};
        len = 0;
        len = file.read(buf,sizeof(buf));
        len = tcpsocket->write(buf,len);
        sendsize += len;

    }while(len > 0 );

    if(sendsize == filesize)
    {
        ui->read->append("文件发送完毕");
        file.close();
        //tcpsocket->close();
    }
}
void ServerWidget::on_buttonfile_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"open","../");
    if(false == filePath.isEmpty())
    {
       filename .clear();
       filesize = 0;
       QFileInfo info(filePath);
       filename = info.fileName();//获取文件名称
       filesize = info.size();//获取文件大小

       sendsize = 0;
       //打开文件
       file.setFileName(filePath);
       bool isOK = file.open(QIODevice::ReadOnly);
       if(false == isOK)
       {
           qDebug() <<"只读方式打开文件失败  77" ;
       }

       ui->read->append(filePath);
       //ui->buttonfile->setEnabled(false);
       ui->send->setEnabled(true);
    }
    else
    {
        qDebug() <<"选择文件路径出错  62" ;
    }
}


void ServerWidget::on_send_clicked()
{
    QString head = QString("%1##%2").arg(filename).arg(filesize);

    qint64 len = tcpsocket->write(head.toUtf8());
    if(len > 0)
    {
        timer.start(20);
    }
    else
    {
        qDebug() <<"头部信息发送失败  101";
        file.close();
        ui->buttonfile->setEnabled(true);
        ui->send->setEnabled(false);
    }


}

