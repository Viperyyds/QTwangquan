#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include <QTimer>
#include <QLCDNumber>
#include <QTime>
#include <QtMath>
#include <QtCore/qmath.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    a.clear();
    b.clear();//把a,b全部清空
     //将按键0和槽函数btn_logic联系起来,后面的以此类推
    connect(ui->pushButton_0,&QPushButton::clicked,this,[=](){ btn_logic(0);});
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){ btn_logic(1);});
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){ btn_logic(2);});
    connect(ui->pushButton_3,&QPushButton::clicked,this,[=](){ btn_logic(3);});
    connect(ui->pushButton_4,&QPushButton::clicked,this,[=](){ btn_logic(4);});
    connect(ui->pushButton_5,&QPushButton::clicked,this,[=](){ btn_logic(5);});
    connect(ui->pushButton_6,&QPushButton::clicked,this,[=](){ btn_logic(6);});
    connect(ui->pushButton_7,&QPushButton::clicked,this,[=](){ btn_logic(7);});
    connect(ui->pushButton_8,&QPushButton::clicked,this,[=](){ btn_logic(8);});
    connect(ui->pushButton_9,&QPushButton::clicked,this,[=](){ btn_logic(9);});

    //将运算符和槽函数绑定起来
    connect(ui->pushButton_jia ,&QPushButton::clicked,this,[=](){ btn_logic(0,"+");});
    connect(ui->pushButton_jian ,&QPushButton::clicked,this,[=](){ btn_logic(0,"-");});
    connect(ui->pushButton_cheng ,&QPushButton::clicked,this,[=](){ btn_logic(0,"*");});
    connect(ui->pushButton_chu ,&QPushButton::clicked,this,[=](){ btn_logic(0,"/");});
    connect(ui->pushButton_deng ,&QPushButton::clicked,this,[=](){ btn_logic(0,"=");});
    connect(ui->pushButton_11 ,&QPushButton::clicked,this,[=](){ btn_logic(0,"%");});
    connect(ui->pushButton_12,&QPushButton::clicked,this,[=](){btn_logic(0,"ping");});
    connect(ui->pushButton_13,&QPushButton::clicked,this,[=](){btn_logic(0,"y");});
    connect(ui->pushButton_14,&QPushButton::clicked,this,[=](){btn_logic(0,"kaifang");});
    connect(ui->pushButton_15,&QPushButton::clicked,this,[=](){btn_logic(0,"LN");});
    connect(ui->pushButton_16,&QPushButton::clicked,this,[=](){btn_logic(0,"e");});
    connect(ui->pushButton_17,&QPushButton::clicked,this,[=](){btn_logic(0,"huashi");});
    connect(ui->pushButton_18,&QPushButton::clicked,this,[=](){btn_logic(0,"date");});



    connect(ui->pushButton_10,&QPushButton::clicked,this,[=]()
    {   a.clear();
        b.clear();
        //对a的内容进行更新
        ui->lineEdit->setText(a);
    });//把清零键的功能加上
    //退格处理
    connect(ui->pushButton_tui,&QPushButton::clicked,this,[=]()
    {
      a.chop(1);//后面跟的一就是字符串a的最后一个字符删除掉
      ui->lineEdit->setText(a);//把a更新显示出来
    });



    lcd = new QLCDNumber();
    lcd->setDigitCount(10);
    lcd->setMode(QLCDNumber::Dec);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    timer = new QTimer;
    timer->setInterval(1000);//设置timer这个定时器每一秒发送一次timeout的信号
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));

}



 void Widget::btn_logic(int x,QString i)//x是按键值，还可以用来判断此时点下的是数字还是运算符
 {
     if(i==" ")
     {

        a += QString::number(x);//这里的加法是字符串的叠加，不是直接进行代数运算

     }
     else if(x == 0)
     {
         if(i != "=")
       {
             if (i != "date")
             {
                 b.insert(0,a);//如果在这里输入了一个运算符，那么要将a的值插入到数组b[0]里面
                 a.clear();
                 b.insert(1,i);//将运算符插入到数组b[1]里面
             }
             else if(i == "date")
             {
                 d.insert(0,a);
                 a.clear();
             }
       }
         else if(i != "ping")
         {

            b.insert(2,a);//按下=后把此时a的值放入到b[2]里面
            den_logic();//这里这个函数就是最后的运算函数

         }
         else if(i == "ping" || i == "kaifang" || i == "LN" || i == "e" || i == "huashi")
         {
            den_logic();
         }

     }
     ui->lineEdit->setText(a);//将ui里面显示出a的当前值
 }


 void Widget::den_logic()
 {
     a.clear();
     if(b.at(1) == "+")
     {
        a += QString::number(QString(b.at(0)).toDouble()+QString(b.at(2)).toDouble());
     }
     else if(b.at(1) == "-")
     {
        a += QString::number(QString(b.at(0)).toDouble()-QString(b.at(2)).toDouble());
     }
     else if(b.at(1) == "*")
     {
        a += QString::number(QString(b.at(0)).toDouble()*QString(b.at(2)).toDouble());
     }
     else if(b.at(1) == "/")
     {
        if(b.at(2) != "0")
        {
            a += QString::number(QString(b.at(0)).toDouble()/QString(b.at(2)).toDouble());
        }
        else
        {
           a = "想什么啊" ;
        }
     }
     else if(b.at(1) == "%")
     {
         a +=  QString::number(QString(b.at(0)).toInt()%QString(b.at(2)).toInt());

     }
     else if(b.at(1) == "ping")
     {
         a +=  QString::number(QString(b.at(0)).toDouble()*QString(b.at(0)).toDouble());

     }
     else if(b.at(1) == "y")
     {
         a += QString::number(pow(QString(b.at(0)).toInt(),QString(b.at(2)).toInt()));
     }
     else if(b.at(1) == "kaifang")
     {
         a += QString::number(sqrt(QString(b.at(0)).toDouble()));
     }
     else if(b.at(1) == "LN")
     {
         a += QString::number(qLn(QString(b.at(0)).toDouble()));
     }
     else if(b.at(1) == "e")
     {
         a += QString::number(qExp(QString(b.at(0)).toDouble()));
     }
     else if(b.at(1) == "huashi")
     {
         a += QString::number(QString(b.at(0)).toDouble()*9/5+32);
     }


     ui->lineEdit->setText(a);
 }

void Widget::onTimerOut()//时间显示函数
{
    QTime time = QTime::currentTime();
    ui->lcdnumber->display(time.toString("hh,mm,ss"));
}




Widget::~Widget()
{
    delete ui;
}












