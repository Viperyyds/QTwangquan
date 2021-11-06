#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void btn_logic(int x,QString i=" ");
    void den_logic();


public:
    QString a;//a用来储存LineEdit里面的内容
    QStringList b;//b用来存储点击过的运算符
    QStringList d;//d用来存储日期计算需要的值
private:
    QLCDNumber *lcd;
    QTimer *timer;

public slots:
     void onTimerOut();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
