#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QtDebug>
#include<QMessageBox>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    tcpsocket = NULL;
    tcpsocket = new QTcpSocket(this);
    isstart = true;
    setWindowTitle("客户端");

    connect(tcpsocket,&QTcpSocket::connected,
            [=]()
    {
       ui->textEditread->setText("成功和服务器建立连接");

    });
    connect(tcpsocket,&QTcpSocket::readyRead,
            [=]()
    {
        QByteArray buf = tcpsocket->readAll();
        ui->textEditread->append(buf);


        //QByteArray buf = tcpsocket->readAll();
        if(true == isstart)
        {
            isstart = false;
            filename = QString(buf).section("##",0,0);
            filesize = QString(buf).section("##",1,1).toInt();
            recvsize = 0;


            file.setFileName(filename);
            bool isok =file.open(QIODevice::WriteOnly);
            if(false == isok)
            {
                qDebug() <<"writeonly error  40";
            }
        }
        else
        {
            qint64 len = file.write(buf);
            recvsize +=len;

            if(recvsize == filesize)
            {
                file.close();
                QMessageBox::information(this,"完成","文件传输完成");//弹出对话框

                //tcpsocket->disconnectFromHost();
                //tcpsocket->close();
            }
        }
    });
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_pushButton_clicked()
{
    QString ip = ui->lineEdit_2->text();
    qint16 port = ui->lineEdit->text().toInt();

    tcpsocket->connectToHost(ip,port);
}


void ClientWidget::on_pushButton_2_clicked()
{
    if(tcpsocket == NULL)
    {
        return;
    }
    QString str = ui->textEditwrite->toPlainText();
    tcpsocket->write(str.toUtf8().data());
    ui->textEditread->append(str);
    ui->textEditwrite->clear();
}


void ClientWidget::on_pushButton_3_clicked()
{
    tcpsocket->disconnectFromHost();
    tcpsocket->close();
    tcpsocket = NULL;
}


void ClientWidget::on_pushButton_4_clicked()
{
    ui->textEditread->clear();
}

