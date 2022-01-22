#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>//监听套接字
#include <QTcpSocket>//通讯套接字
#include<QFile>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

private:
    Ui::ServerWidget *ui;
    QFile file;
public:
    QTcpServer *tcpserver;
    QTcpSocket *tcpsocket;
private:
    QString filename;
    qint64 filesize;
    qint64 sendsize;
    QTimer timer;
public:
    void senddata();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_buttonfile_clicked();
    void on_send_clicked();
};
#endif // SERVERWIDGET_H
