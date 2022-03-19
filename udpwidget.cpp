#include "udpwidget.h"
#include "ui_udpwidget.h"
#include<QHostAddress>

UdpWidget::UdpWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UdpWidget)
{
    ui->setupUi(this);

    udpsocket = new QUdpSocket(this);

    //udpsocket->bind(8888);
    udpsocket->bind(QHostAddress::AnyIPv4,8888);

    udpsocket->joinMulticastGroup(QHostAddress("224.0.0.2"));

    setWindowTitle("服务器端口为：8888");
    connect(udpsocket,&QUdpSocket::readyRead,this,&UdpWidget::dealmsg);
}

void UdpWidget::dealmsg()
{
    char buf[1024] = {0};
    QHostAddress cliaddr;//对方地址
    quint16 port;//对方端口
    qint64 len = udpsocket->readDatagram(buf,sizeof(buf),&cliaddr, &port);

    if(len > 0)
    {
        QString str = QString("[%1:%2]  %3")
                .arg(cliaddr.toString())
                .arg(port)
                .arg(buf);
        ui->textEdit->clear();
        ui->textEdit->append(str);
    }
}

UdpWidget::~UdpWidget()
{
    delete ui;
}


void UdpWidget::on_pushButtonsend_clicked()
{
    //先获取对方的IP和端口
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();

    QString str = ui->textEdit->toPlainText();

    udpsocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
}


void UdpWidget::on_pushButtonclose_clicked()
{
    udpsocket->close();
}

