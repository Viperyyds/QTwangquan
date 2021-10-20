#  1.对QT最基础的main函数的解析

```c
#include "mywidget.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();
    return a.exec();
}

```

（1）QT的main函数和C++基本相同，主要都是头文件+main函数的形式。

（2）QApplication是应用程序类的头文件，在QT中基本上所有的头文件都是以Q开头，前两个字母大写。

（3）'' MyWidget w" MyWidget是继承与QWidget,QWidget是一类窗口基类，其他所有的窗口基本都是他的子类，MyWidget也是一个窗口类，w在这里就是表示一个窗口。

（4）w.show()   在QT里面窗口默认是隐藏的，需要人为的加一个show函数来将窗口显示出来

（5）"return a.exec()" 这一句和C++里面的 "return 0" 作用是类似的，都是结束程序，但是这里的a.exec()是一个函数，它         的作用就是使程序进入一个死循环，这样做的话就可以使程序的窗口一直存在直到用户操作为止。也可以写成

```c
a.exec();
return 0;
```

(6) main函数的基本程序框架就可以概括为

```c
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   //自己写的函数
    return a.exec();
}

```

#  2.pro文件的解析

 ```c
 QT       += core gui
 greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
 CONFIG += c++11
 TARGET = 01_QtTest
 SOURCES += \
     main.cpp \
     mywidget.cpp
 HEADERS += \
     mywidget.h
 
 ```

(1)"QT       += core gui" 这句代码是起一个连接作用的，在.h 文件中我们会用到一个QWidget的类，这个类就需要这句代码将其连接到整个文件中去。

(2)"TARGET = 01_QtTest" 这句话说的是生成的应用程序的名称为01_QtTest，在编译是会自动的生成。

 (3)后面的sources和headers分别表示的是源文件（.cpp）和头文件的来源(.h)

#  3.代码实例

![](D:\桌面\zhaopian.png)

代码中main函数的基本框架都是一样，在这里面有一个父对象与子对象的概念。在窗口里面当有多个窗口要出现的时候，就会有一个父对象与子对象的关系。例如在一个大的窗口里面我希望设置几个按钮或者是几个其他的控件，那么我就会希望有一个作为主体的框架，其他的子框架就嵌入其中，这个时候就要用到父对象了。设置方法有两种：

第一种用"setparent(&变量)"     

```c
b.setParent(&w);//指定父对象
```

第二种的话就是使用传参函数

```c
QPushButton b1(&w);
```





