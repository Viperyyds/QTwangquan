#  1.类的定义形式

(1)一个最基本的类的定义，class后面接的是类名（"student"）,public表示公有，在类的定义之外，给一个类的对象也可以调用；private表示类的私有数据，在类里面private是数据的默认形式，要通过类自身定义的函数才能调用，其他所有的外部函数都是不可以访问的。protected表示受保护的数据类型，对外部访问者而言和私有的数据类型是一样的，在继承中会使用到。

```c++
class Student
{
    public:  //公有
    private://私有
    protected:
        
}
```

(2)

```c++
class Clock
{
    public : 
    void setClock(int h,int m,int,s)
    {
        hours=h;
        minute=m;
        second=s;
    }
    void showClock()
    {
       cout<<hours<<":"<<minute<<":"<<second<<endl; 
    }
    private :
    int hours,minute,second;
};
int main()
{
    char a;
    Clock.clock;
    clock.setClock(12,0,0);
    clock.showClock;
    cin>>a;
    return 0;
}

    
```

上面写出了一个简单的类的封装和应用。在实际应用的时候我们常常需要用到某一类数据，类的封装就很好的解决了这样的问题。代码里面首先定义了一个Clock类，在Clock类里面定义了两个成员函数setClock和showClock（都是公有函数），在main函数中要用到Clock类是，用'类名+变量名'重新定义了一个类的对象，然后用这个对象调用类里面的两个函数setClock和showClock。这里要注意一点，就是成员函数是通过括号后面的数据直接传参（clock.setClock(12,0,0)）。另外补充一下，在类的成员函数的定义中除了，在上面写出的隐式内联外，还可以在类的定义外去定义。

```c++
class Clock
{
    void setClock(int h,int m,int s);
};
void Clock::setClock(int h, int m,int s)
{
    hour=h;
    minute=m;
    second=s;
        
}
```

	#  2.类的构造函数与析构函数

1.构造函数在面对对象的编程中是非常普遍的。其作用是在对象创建时给对象一个特定的初始状态，如果没有定义构造函数的话，那么编译器会自动生成一个默认的构造函数。构造函数的名称就是类名。构造函数是没有返回类型的，这与他的初始化功能是相对应的。

```c++
class Clock
{
    public : 
    Clock();//Clock(int a,int b,int c)含参形式的构造函数
    void setClock(int h,int m,int,s)
    {
        hours=h;
        minute=m;
        second=s;
    }
};
Clock::Clock()
{}
int main()
{
    Clock clock;
}
```

上述的代码写的就是一个无参的构造函数，这个构造函数实际上和系统默认的构造函数是基本相同的。

2.析构函数和构造函数在大体上是一样的，构造函数是在对象被定义的时候调用，而析构函数是在对象被删除是使用。和构造函数一样，当用户没有定义析构函数是，系统同样会默认的生成一个析构函数。析构函数的写法如下：

```c++
	~Clock();//class destructor
```

如果在构造函数中使用了new类型的数据那么在析构函数中必须提供使用delete的析构函数。