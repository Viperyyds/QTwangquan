#ifndef UDPWIDGET_H
#define UDPWIDGET_H

#include <QWidget>
#include<QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class UdpWidget; }
QT_END_NAMESPACE

class UdpWidget : public QWidget
{
    Q_OBJECT

public:
    UdpWidget(QWidget *parent = nullptr);
    ~UdpWidget();
public:
    void dealmsg();

private slots:
    void on_pushButtonsend_clicked();

    void on_pushButtonclose_clicked();

private:
    Ui::UdpWidget *ui;

    QUdpSocket *udpsocket;//Udp套接字
};
#endif // UDPWIDGET_H
