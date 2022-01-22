#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include<QFile>


namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private:
    Ui::ClientWidget *ui;
    QFile file;
    QString filename;
    qint64 filesize;
    qint64 recvsize;
public:
    QTcpSocket *tcpsocket;

    //QString filename;
    //qint64 filesize;
    //qint64 recvsize;

    bool isstart;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

#endif // CLIENTWIDGET_H
