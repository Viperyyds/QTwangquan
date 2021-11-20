#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
public:
    void btn_logic(int x,QString i=" ");
    //void show();
public:
    QString a;
    QStringList b;
    QStringList d;
    QStringList l;


private slots:
    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
