// #### 4.6.1 继承的基本语法
// 例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同
// 接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处
#include<iostream>
using namespace std;
//普通的界面实现
//Java页面
class Java
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }

    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }

    void left()
    {
        cout << "Java,Python,C++...(公共分类列表)" << endl;
    }

    void content()
    {
        cout << "JAVA学科视频" << endl;
    }
};

//Python页面
class Python
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }

    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }

    void left()
    {
        cout << "Java,Python,C++...(公共分类列表)" << endl;
    }

    void content()
    {
        cout << "Python学科视频" << endl;
    }
};

//C++页面
class CPP
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }

    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }

    void left()
    {
        cout << "Java,Python,C++...(公共分类列表)" << endl;
    }

    void content()
    {
        cout << "C++学科视频" << endl;
    }
};

void test01()
{
    //Java页面
    cout << "Java下载视频页面如下： " << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "--------------------" << endl;
    //Python页面
    cout << "Python下载视频页面如下： " << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "--------------------" << endl;
    //C++页面
    cout << "C++下载视频页面如下： " << endl;
    CPP cp;
    cp.header();
    cp.footer();
    cp.left();
    cp.content();
}

int main()
{
    test01();
    system("pause");
    return 0;
}

//继承的界面实现
//公共页面
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }

    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }

    void left()
    {
        cout << "Java,Python,C++...(公共分类列表)" << endl;
    }
};

//Java页面
class Java : public BasePage
{
public:
    void content()
    {
        cout << "JAVA学科视频" << endl;
    }
};

//Python页面
class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python学科视频" << endl;
    }
};

//C++页面
class CPP : public BasePage
{
public:
    void content()
    {
        cout << "C++学科视频" << endl;
    }
};

void test01()
{
    //Java页面
    cout << "Java下载视频页面如下： " << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "--------------------" << endl;
    //Python页面
    cout << "Python下载视频页面如下： " << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "--------------------" << endl;
    //C++页面
    cout << "C++下载视频页面如下： " << endl;
    CPP cp;
    cp.header();
    cp.footer();
    cp.left();
    cp.content();
}

int main()
{
    test01();
    system("pause");
    return 0;
}

//**总结：**
// 继承的好处：==可以减少重复的代码==
// class A : public B;
// A 类称为子类 或 派生类
// B 类称为父类 或 基类
// **派生类中的成员，包含两大部分**：
// 一类是从基类继承过来的，一类是自己增加的成员。
// 从基类继承过过来的表现其共性，而新增的成员体现了其个性。

//#### 4.6.2 继承方式
// 继承的语法：`class 子类 : 继承方式  父类`
// **继承方式一共有三种：**
// * 公共继承
// * 保护继承
// * 私有继承
class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

//公共继承
class Son1 : public Base1
{
public:
    void func()
    {
        m_A; //可访问 public权限
        m_B; //可访问 protected权限
        //m_C; //不可访问
    }
};

void myClass()
{
    Son1 s1;
    s1.m_A; //其他类只能访问到公共权限
}

//保护继承
class Base2
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son2 : protected Base2
{
public:
    void func()
    {
        m_A; //可访问 protected权限
        m_B; //可访问 protected权限
        //m_C; //不可访问
    }
};

void myClass2()
{
    Son2 s;
    //s.m_A; //不可访问
}

//私有继承
class Base3
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son3 : private Base3
{
public:
    void func()
    {
        m_A; //可访问 private权限
        m_B; //可访问 private权限
        //m_C; //不可访问
    }
};

class GrandSon3 : public Son3
{
public:
    void func()
    {
        //Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
        //m_A;
        //m_B;
        //m_C;
    }
};


// #### 4.6.3 继承中的对象模型
// **问题：**从父类继承过来的成员，哪些属于子类对象中
class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son : public Base
{
public:
    int m_D;
};

void test01()
{
    cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}

//结论： 父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到


// #### 4.6.4 继承中构造和析构顺序
// 子类继承父类后，当创建子类对象，也会调用父类的构造函数
// 问题：父类和子类的构造和析构顺序是谁先谁后
class Base
{
public:
    Base()
    {
        cout << "Base构造函数!" << endl;
    }

    ~Base()
    {
        cout << "Base析构函数!" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son构造函数!" << endl;
    }

    ~Son()
    {
        cout << "Son析构函数!" << endl;
    }
};

void test01()
{
    //继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
    Son s;
}

int main()
{
    test01();
    system("pause");
    return 0;
}

//总结：继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反


// #### 4.6.5 继承同名成员处理方式
// 问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？
// * 访问子类同名成员   直接访问即可
// * 访问父类同名成员   需要加作用域
class Base
{
public:
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base - func()调用" << endl;
    }

    void func(int a)
    {
        cout << "Base - func(int a)调用" << endl;
    }

public:
    int m_A;
};

class Son : public Base
{
public:
    Son()
    {
        m_A = 200;
    }

    //当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
    //如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
    void func()
    {
        cout << "Son - func()调用" << endl;
    }

public:
    int m_A;
};

void test01()
{
    Son s;
    cout << "Son下的m_A = " << s.m_A << endl;
    cout << "Base下的m_A = " << s.Base::m_A << endl;
    s.func();
    s.Base::func();
    s.Base::func(10);
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}

// 总结：
// 1. 子类对象可以直接访问到子类中同名成员
// 2. 子类对象加作用域可以访问到父类同名成员
// 3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数


// #### 4.6.6 继承同名静态成员处理方式
// 问题：继承中同名的静态成员在子类对象上如何进行访问？
// 静态成员和非静态成员出现同名，处理方式一致
// - 访问子类同名成员   直接访问即可
// - 访问父类同名成员   需要加作用域
class Base
{
public:
    static void func()
    {
        cout << "Base - static void func()" << endl;
    }

    static void func(int a)
    {
        cout << "Base - static void func(int a)" << endl;
    }

    static int m_A;
};

int Base::m_A = 100;

class Son : public Base
{
public:
    static void func()
    {
        cout << "Son - static void func()" << endl;
    }

    static int m_A;
};

int Son::m_A = 200;
//同名成员属性
void test01()
{
    //通过对象访问
    cout << "通过对象访问： " << endl;
    Son s;
    cout << "Son  下 m_A = " << s.m_A << endl;
    cout << "Base 下 m_A = " << s.Base::m_A << endl;
    //通过类名访问
    cout << "通过类名访问： " << endl;
    cout << "Son  下 m_A = " << Son::m_A << endl;
    cout << "Base 下 m_A = " << Son::Base::m_A << endl;
}

//同名成员函数
void test02()
{
    //通过对象访问
    cout << "通过对象访问： " << endl;
    Son s;
    s.func();
    s.Base::func();
    cout << "通过类名访问： " << endl;
    Son::func();
    Son::Base::func();
    //出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
    Son::Base::func(100);
}

int main()
{
    //test01();
    test02();
    system("pause");
    return 0;
}

//总结：同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象 和 通过类名）

// #### 4.6.7 多继承语法
// C++允许**一个类继承多个类**
// 语法：` class 子类 ：继承方式 父类1 ， 继承方式 父类2...`
// 多继承可能会引发父类中有同名成员出现，需要加作用域区分
// **C++实际开发中不建议用多继承**
class Base1
{
public:
    Base1()
    {
        m_A = 100;
    }

public:
    int m_A;
};

class Base2
{
public:
    Base2()
    {
        m_A = 200; //开始是m_B 不会出问题，但是改为mA就会出现不明确
    }

public:
    int m_A;
};

//语法：class 子类：继承方式 父类1 ，继承方式 父类2
class Son : public Base2, public Base1
{
public:
    Son()
    {
        m_C = 300;
        m_D = 400;
    }

public:
    int m_C;
    int m_D;
};

//多继承容易产生成员同名的情况
//通过使用类名作用域可以区分调用哪一个基类的成员
void test01()
{
    Son s;
    cout << "sizeof Son = " << sizeof(s) << endl;
    cout << s.Base1::m_A << endl;
    cout << s.Base2::m_A << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}


// #### 4.6.8 菱形继承
// **菱形继承概念：**
//两个派生类继承同一个基类
//又有某个类同时继承者两个派生类
//这种继承被称为菱形继承，或者钻石继承

// 1.羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性。
// 2.草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以
class Animal
{
public:
    int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal {};
class Tuo   : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 100;
    st.Tuo::m_Age = 200;
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}