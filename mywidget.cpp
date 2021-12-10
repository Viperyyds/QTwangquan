#include "mywidget.h"
#include "ui_mywidget.h"
#include "QDebug"
#include <QTimer>
#include <QLCDNumber>
#include <QTime>
#include <QtMath>
#include <QtCore/qmath.h>
int r=0;
float g ;
float h;
float j;
float k;
float p;
float o;



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

    connect(ui->pushButton_21,&QPushButton::clicked,this,[=]()
    {   a.clear();
        b.clear();
        d.clear();
        l.clear();
        ui->lineEdit_1->setText(a);
        ui->lineEdit_2->setText(a);
        ui->lineEdit_3->setText(a);
    });

    connect(ui->pushButton_22,&QPushButton::clicked,this,[=]()
    {
      a.chop(1);
      ui->lineEdit_1->setText(a);
    });

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
           g = QString(b.at(0)).toFloat();
           a.clear();
       }
       else if(i == "y1")
       {
           b.insert(1,a);
           h= QString(b.at(1)).toFloat();
           a.clear();
       }
       else if(i == "z1")
       {
           b.insert(2,a);
           j= QString(b.at(2)).toFloat();
           a.clear();
       }
       else if(i == "x2")
       {
           d.insert(0,a);
           k= QString(d.at(0)).toFloat();
           a.clear();
       }
       else if(i == "y2")
       {
           d.insert(1,a);
           p= QString(d.at(1)).toFloat();
           a.clear();
       }
       else if(i == "z2")
       {
           d.insert(2,a);
           o= QString(d.at(2)).toFloat();
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
    QString dis1;
    dis1 += QString::number(sqrt((QString(b.at(0)).toFloat()-QString(d.at(0)).toFloat())*(QString(b.at(0)).toFloat()-QString(d.at(0)).toFloat())+(QString(b.at(1)).toFloat()-QString(d.at(1)).toFloat())*(QString(b.at(1)).toFloat()-QString(d.at(1)).toFloat())+(QString(b.at(2)).toFloat()-QString(d.at(2)).toFloat())*(QString(b.at(2)).toFloat()-QString(d.at(2)).toFloat())));
    l.insert(1,dis1);

    QString m;
    b.insert(3, QString::number(QString(d.at(0)).toFloat()-QString(b.at(0)).toFloat()));
    m += b.at(3);
    d.insert(3,m);
    m.clear();

    b.insert(4, QString::number(QString(d.at(1)).toFloat()-QString(b.at(1)).toFloat()));
    m += b.at(4);
    d.insert(4,m);
    m.clear();

    b.insert(5, QString::number(QString(d.at(2)).toFloat()-QString(b.at(2)).toFloat()));
    m += b.at(5);
    d.insert(5,m);
    m.clear();

    b.insert(6,QString::number(QString(d.at(3)).toFloat()/QString(l.at(1)).toFloat()));
    b.insert(7,QString::number(QString(d.at(4)).toFloat()/QString(l.at(1)).toFloat()));
    b.insert(8,QString::number(QString(d.at(5)).toFloat()/QString(l.at(1)).toFloat()));


    QString x,y,z;
    x += QString::number(QString(b.at(0)).toFloat()+QString(b.at(6)).toFloat()*QString(l.at(0)).toFloat());
    y += QString::number(QString(b.at(1)).toFloat()+QString(b.at(7)).toFloat()*QString(l.at(0)).toFloat());
    z += QString::number(QString(b.at(2)).toFloat()+QString(b.at(8)).toFloat()*QString(l.at(0)).toFloat());

    ui->lineEdit_1->setText(x);
    ui->lineEdit_2->setText(y);
    ui->lineEdit_3->setText(z);


}


void MyWidget::on_pushButton_19_clicked()
{
    QString x1,y1,z1;
    x1 += b.at(0);
    y1 += b.at(1);
    z1 += b.at(2);
    ui->lineEdit_6->setText(x1);
    ui->lineEdit_7->setText(y1);
    ui->lineEdit_8->setText(z1);
}


void MyWidget::on_pushButton_20_clicked()
{
    QString x1,y1,z1;
    x1 += d.at(0);
    y1 += d.at(1);
    z1 += d.at(2);
    ui->lineEdit->setText(x1);
    ui->lineEdit_4->setText(y1);
    ui->lineEdit_5->setText(z1);
}



void MyWidget::on_pushButton_23_clicked()
{
   Widget *position = new Widget;
   position->show();
}


void MyWidget::on_pushButton_24_clicked()
{
    r=0;
}

