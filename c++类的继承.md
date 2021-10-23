#  1.继承的基本用法和写法

1.继承和类是分不开的，类的意义在于可以提高我们代码的重复利用性，而继承可以让我们有一个类出发派生出其他的子类。继承的用法：可以用一个类去定义另外的一个类，创建另一个类的时候不需要再重新定义类的数据成员和成员函数，只需要指明创建的这个类是继承于哪一个类就可以了，已有的类称为基类，派生出来的类称作子类。在c++里面，继承有三种方式，公有继承，私有继承，和保护继承（这个和类的数据成员类型是基本一样的），其中用的最多的是公有继承，公有继承有一个明显的特征就是"is a"关系，就是说，我的派生类是基类中的一种。比如，创建一个Fruit类，由Fruit类派生出一个Banana类，因为banana是一种水果，所以说Banana类具有父类的全部数据成员和内部成员函数，但是它自己还是可以有自己独有的数据成员（Banana的果皮结构）。

2.继承的基本写法：

```c++
class Animal
{
    public:
    eat();
    sleep();
};
class Dog :public Animal
{
    bark();
}
```

在上面的Dog类就是一个公有继承的例子，Dog类中有一个他自己的成员函数bark，然后它还会继承Animal类中的eat和sleep两个成员函数。

#  2.基类和派生类

1.一个类可以派生出多个类，这也就是说，一个派生类可以从不同的基类中继承数据和函数。我们使用类派生列表来指定基类：

```c++
class derived-class :access-specifier base-class
```

class+类名，标识符后面跟了一个访问修饰符 access-specifier,是public，protected或private中的一个。下面给出一个基类和派生类的例子：

```c++
class Shape
{
    public:
    void setwidth(int w)
    {
        width=w;
    }
    void setheight(int h)
    {
        height=h;
    }
  
    int width;
    int height;
};
class Rectangle: public Shape
{
    public:
    int Getarea()
    {
        return (width*height);
    }
};
int main()
{
    Rectangle a;
    a.setwidth(5);
    a.setheight(3);
    cout<<"面积为"<<a.Getarea()<<endl;
    return 0;
}
```

上面的例子先给出了一个父类Shape，在父类里面有两个数据成员矩形的长和宽，然后定义了一个子类Rectangle，子类中定义了一个成员函数Getarea用来计算矩形的面积，它的数据就可以直接继承父类Shape里面的width和height，但是需要主义的是如果在Shape里面吧width和height定义为了private类的数据成员的话，公有继承后的Rectangle是不能够访问这两个值的。

#  3.访问的控制和继承

在前面第二点中提到的一样派生类可以访问基类中的所有除私有成员外的全部成员。下图中的表给出了不同权限的不同访问类型：

![image-20211023160919290](C:\Users\AIR15wq\AppData\Roaming\Typora\typora-user-images\image-20211023160919290.png)

#  4.继承类型

1.**公有继承（public）：**当一个类派生自**公有**基类时，基类的**公有**成员也是派生类的**公有**成员，基类的**保护**成员也是派生类的**保护**成员，基类的**私有**成员不能直接被派生类访问，但是可以通过调用基类的**公有**和**保护**成员来访问。

2.**保护继承（protected）：** 当一个类派生自**保护**基类时，基类的**公有**和**保护**成员将成为派生类的**保护**成员。

3.**私有继承（private）：**当一个类派生自**私有**基类时，基类的**公有**和**保护**成员将成为派生类的**私有**成员。

#  5.多继承

多继承的概念：一个子类可以从多个父类中继承数据成员和函数，可以提升代码的可重复利用。下面给出一个实例：

```c++
class Shape//基类
{
    public:
    void setwidth(int w)
    {
        width=w;
    }
    void setheight(int h)
    {
        height=h;
    }
  
    int width;
    int height;
};
class Cost//基类
{
    int Getcost(area)
    {
        return area*70;
    }
}
class Rectangle: public Shape,public Cost//派生类，多继承的写法
{
    public:
    int Getarea()
    {
        return (width*height);
    }
};
int main()
{
    Rectangle a;
    int area;
    a.setwidth(5);
    a.setheight(3);
    area=a.Getarea();
    cout<<"面积为"<<a.Getarea()<<endl;
    cout<<"造价为"<<a.Getcost(area)<<endl;
    return 0;
}
```

在Rectangle类继承了两个父对象Shape和Cost，通过这两个这两个父对象里面的成员函数计算出了一块矩形区域的面积和造价。