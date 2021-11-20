#include "mywidget.h"
#include "ui_mywidget.h"
#include "QDebug"
#include <QTimer>
#include <QLCDNumber>
#include <QTime>
#include <QtMath>
#include <QtCore/qmath.h>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,&QPushButton::clicked,this,[=](){ btn_logic(0);});
    connect(ui->pushButton_1,&QPushButton::clicked,this,[=](){ btn_logic(1);});
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){ btn_logic(2);});
    connect(ui->pushButton_3,&QPushButton::clicked,this,[=](){ btn_logic(3);});
    connect(ui->pushButton_4,&QPushButton::clicked,this,[=](){ btn_logic(4);});
    connect(ui->pushButton_5,&QPushButton::clicked,this,[=](){ btn_logic(5);});
    connect(ui->pushButton_6,&QPushButton::clicked,this,[=](){ btn_logic(6);});
    connect(ui->pushButton_7,&QPushButton::clicked,this,[=](){ btn_logic(7);});
    connect(ui->pushButton_8,&QPushButton::clicked,this,[=](){ btn_logic(8);});
    connect(ui->pushButton_9,&QPushButton::clicked,this,[=](){ btn_logic(9);});
    connect(ui->pushButton_10,&QPushButton::clicked,this,[=](){ btn_logic(10);});

    connect(ui->pushButton_11,&QPushButton::clicked,this,[=](){btn_logic(0,"x1");});
    connect(ui->pushButton_12,&QPushButton::clicked,this,[=](){btn_logic(0,"y1");});
    connect(ui->pushButton_13,&QPushButton::clicked,this,[=](){btn_logic(0,"z1");});

    connect(ui->pushButton_14,&QPushButton::clicked,this,[=](){btn_logic(0,"x2");});
    connect(ui->pushButton_15,&QPushButton::clicked,this,[=](){btn_logic(0,"y2");});
    connect(ui->pushButton_16,&QPushButton::clicked,this,[=](){btn_logic(0,"z2");});

    connect(ui->pushButton,&QPushButton::clicked,this,[=](){btn_logic(0,"Line");});

    //connect(ui->pushButton_19,&QPushButton::clicked,this,[=](){show();});
}



void MyWidget::btn_logic(int x,QString i) {
   if(i == " ") {
       if(x == 10) {
           a += ".";
       } else {
           a += QString::number(x);
       }
   }
   else if(x == 0)
   {
       if(i == "x1")
       {
           b.insert(0,a);
           a.clear();
       }
       else if(i == "y1")
       {
           b.insert(1,a);
           a.clear();
       }
       else if(i == "z1")
       {
           b.insert(2,a);
           a.clear();
       }
       else if(i == "x2")
       {
           d.insert(0,a);
           a.clear();
       }
       else if(i == "y2")
       {
           d.insert(1,a);
           a.clear();
       }
       else if(i == "z2")
       {
           d.insert(2,a);
           a.clear();
       }
       else if(i == "Line")
       {
           l.insert(0,a);
           a.clear();
       }
   }
   ui->lineEdit_1->setText(a);

}


/*void MyWidget::show()
{
   ui->lineEdit_2->setText(b.at(0));
}*/


MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_pushButton_18_clicked()
{
    QString dis;
    dis += QString::number(sqrt((QString(b.at(0)).toFloat()-QString(d.at(0)).toFloat())*(QString(b.at(0)).toFloat()-QString(d.at(0)).toFloat())+(QString(b.at(1)).toFloat()-QString(d.at(1)).toFloat())*(QString(b.at(1)).toFloat()-QString(d.at(1)).toFloat())+(QString(b.at(2)).toFloat()-QString(d.at(2)).toFloat())*(QString(b.at(2)).toFloat()-QString(d.at(2)).toFloat())));
    ui->lineEdit_1->setText(dis);
}


void MyWidget::on_pushButton_17_clicked()
{
    QString dis;
    dis += QString::number(sqrt((QString(b.at(0)).toFloat()-QString(d.at(0)).toFloat())*(QString(b.at(0)).toFloat()-QString(d.at(0)).toFloat())+(QString(b.at(1)).toFloat()-QString(d.at(1)).toFloat())*(QString(b.at(1)).toFloat()-QString(d.at(1)).toFloat())+(QString(b.at(2)).toFloat()-QString(d.at(2)).toFloat())*(QString(b.at(2)).toFloat()-QString(d.at(2)).toFloat())));
    QString d,e,f;
    d += QString::number(QString(b.at(0)).toFloat()-QString(d.at(0)).toFloat());
    e += QString::number(QString(b.at(1)).toFloat()-QString(d.at(1)).toFloat());
    f += QString::number(QString(b.at(2)).toFloat()-QString(d.at(2)).toFloat());

    QString r,s,t;
    r += QString::number(d.toFloat()/dis.toFloat());
    s += QString::number(e.toFloat()/dis.toFloat());
    t += QString::number(f.toFloat()/dis.toFloat());



    QString x,y,z;
    x += QString::number(QString(b.at(0)).toFloat()+r.toFloat()*QString(l.at(0)).toFloat());
    y += QString::number(QString(b.at(1)).toFloat()+s.toFloat()*QString(l.at(0)).toFloat());
    z += QString::number(QString(b.at(2)).toFloat()+t.toFloat()*QString(l.at(0)).toFloat());

    ui->lineEdit_1->setText(x);
    ui->lineEdit_2->setText(y);
    ui->lineEdit_3->setText(z);

    /*x.clear();
    y.clear();
    z.clear();

    a.clear();
    b.clear();
    c.clear();*/


}

