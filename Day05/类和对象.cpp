// ## **4** 类和对象
// C++面向对象的三大特性为：==封装、继承、多态==
// C++认为==万事万物都皆为对象==，对象上有其属性和行为
// **例如：**
// 人可以作为对象，属性有姓名、年龄、身高、体重...，行为有走、跑、跳、吃饭、唱歌...
// 车也可以作为对象，属性有轮胎、方向盘、车灯...,行为有载人、放音乐、放空调...
// 具有相同性质的==对象==，我们可以抽象称为==类==，人属于人类，车属于车类

// ### 4.1 封装
// #### 4.1.1  封装的意义
// 封装是C++面向对象三大特性之一
// 封装的意义：
// * 将属性和行为作为一个整体，表现生活中的事物
// * 将属性和行为加以权限控制
// **封装意义一：**
// 在设计类的时候，属性和行为写在一起，表现事物
// **语法：** `class 类名{   访问权限： 属性  / 行为  };`
//示例1
#include<iostream>
using namespace std;
const double PI = 3.14;
//1、封装的意义
//将属性和行为作为一个整体，用来表现生活中的事物
//封装一个圆类，求圆的周长
//class代表设计一个类，后面跟着的是类名
class Circle
{
public://访问权限  公共的权限
    //属性
    int m_r;//半径
    //行为  (获取到圆的周长)
    double calculateZC()
    {
        return m_r*2*PI;
    }
};
int main0()
{
    //通过圆类创建元的对象
    //c1就是一个具体的圆
    Circle c1;
    c1.m_r = 10; //给圆对象的半径 进行赋值操作
    //2 * pi * 10 = = 62.8
    cout << "圆的周长为： " << c1.calculateZC() << endl;
    system("pause");
    return 0;
}
//示例2
//学生类
class Student {
public:
    void setName(string name) {
        m_name = name;
    }
    void setID(int id) {
        m_id = id;
    }
    void showStudent() {
        cout << "name:" << m_name << " ID:" << m_id << endl;
    }
    string m_name;
    int m_id;
};
int main1() {
    Student stu;
    stu.setName("德玛西亚");
    stu.setID(250);
    stu.showStudent();
    system("pause");
    return 0;
}
// **封装意义二：**
// 类在设计时，可以把属性和行为放在不同的权限下，加以控制
// 访问权限有三种：
// 1. public        公共权限
// 2. protected 保护权限
// 3. private      私有权限
//三种权限
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问
//私有权限  private    类内可以访问  类外不可以访问

class Person01
{
    //姓名  公共权限
public:
    string m_Name;
    //汽车  保护权限
protected:
    string m_Car;
    //银行卡密码  私有权限
private:
    int m_Password;
public:
    void func()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
};
int main2() {
    Person01 p;
    p.m_Name = "李四";
    //p.m_Car = "奔驰";  //保护权限类外访问不到
    //p.m_Password = 123; //私有权限类外访问不到
    system("pause");
    return 0;
}


// #### 4.1.2 struct和class区别
// 在C++中 struct和class唯一的**区别**就在于 **默认的访问权限不同**
// 区别：
// * struct 默认权限为公共
// * class   默认权限为私有
class C1
{
    int  m_A; //默认是私有权限
};
struct C2
{
    int m_A;  //默认是公共权限
};
int main3() {
    C1 c1;
    c1.m_A = 10; //错误，访问权限是私有
    C2 c2;
    c2.m_A = 10; //正确，访问权限是公共
    system("pause");
    return 0;
}

// #### 4.1.3 成员属性设置为私有
// **优点1：**将所有成员属性设置为私有，可以自己控制读写权限
// **优点2：**对于写权限，我们可以检测数据的有效性
class Person {
public:
    //姓名设置可读可写
    void setName(string name) {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }
    //获取年龄
    int getAge() {
        return m_Age;
    }
    //设置年龄
    void setAge(int age) {
        if (age < 0 || age > 150) {
            cout << "你个老妖精!" << endl;
            return;
        }
        m_Age = age;
    }
    //情人设置为只写
    void setLover(string lover) {
        m_Lover = lover;
    }
private:
    string m_Name; //可读可写  姓名
    int m_Age; //只读  年龄
    string m_Lover; //只写  情人
};
int main4() {
    Person p;
    //姓名设置
    p.setName("张三");
    cout << "姓名： " << p.getName() << endl;
    //年龄设置
    p.setAge(50);
    cout << "年龄： " << p.getAge() << endl;
    //情人设置
    p.setLover("苍井");
    //cout << "情人： " << p.m_Lover << endl;  //只写属性，不可以读取
    system("pause");
    return 0;
}

// ### 4.2 对象的初始化和清理
//生活中我们买的电子产品都基本会有出厂设置，在某一天我们不用时候也会删除一些自己信息数据保证安全
//C++中的面向对象来源于生活，每个对象也都会有初始设置以及 对象销毁前的清理数据的设置。

// #### 4.2.1 构造函数和析构函数
// 对象的**初始化和清理**也是两个非常重要的安全问题
//一个对象或者变量没有初始状态，对其使用后果是未知
// 同样的使用完一个对象或变量，没有及时清理，也会造成一定的安全问题
// c++利用了**构造函数**和**析构函数**解决上述问题，这两个函数将会被编译器自动调用，完成对象初始化和清理工作。
// 对象的初始化和清理工作是编译器强制要我们做的事情，因此如果**我们不提供构造和析构，编译器会提供**
// **编译器提供的构造函数和析构函数是空实现。**

// * 构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。

// * 析构函数：主要作用在于对象**销毁前**系统自动调用，执行一些清理工作。

// **构造函数语法：**`类名(){}`
// 1. 构造函数，没有返回值也不写void
// 2. 函数名称与类名相同
// 3. 构造函数可以有参数，因此可以发生重载
// 4. 程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次

// **析构函数语法：** `~类名(){}`
// 1. 析构函数，没有返回值也不写void
// 2. 函数名称与类名相同,在名称前加上符号  ~
// 3. 析构函数不可以有参数，因此不可以发生重载
// 4. 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次
class Person
{
public:
    //构造函数
    Person()
    {
        cout << "Person的构造函数调用" << endl;
    }
    //析构函数
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
};
void test01()
{
    Person p;
}
int main6() {
    test01();
    system("pause");
    return 0;
}


// #### 4.2.2 构造函数的分类及调用
// 两种分类方式：
//按参数分为： 有参构造和无参构造
//按类型分为： 普通构造和拷贝构造
// 三种调用方式：
//括号法
//显示法
//隐式转换法
//1、构造函数分类
// 按照参数分类分为 有参和无参构造   无参又称为默认构造函数
// 按照类型分类分为 普通构造和拷贝构造
class Person {
public:
    //无参（默认）构造函数
    Person() {
        cout << "无参构造函数!" << endl;
    }
    //有参构造函数
    Person(int a) {
        age = a;
        cout << "有参构造函数!" << endl;
    }
    //拷贝构造函数
    Person(const Person& p) {
        age = p.age;
        cout << "拷贝构造函数!" << endl;
    }
    //析构函数
    ~Person() {
        cout << "析构函数!" << endl;
    }
public:
    int age;
};
//2、构造函数的调用
//调用无参构造函数
void test01() {
    Person p; //调用无参构造函数
}
//调用有参的构造函数
void test02() {
    //2.1  括号法，常用
    Person p1(10);
    //注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
    //Person p2();
    //2.2 显式法
    Person p2 = Person(10);
    Person p3 = Person(p2);
    //Person(10)单独写就是匿名对象  当前行结束之后，马上析构
    //2.3 隐式转换法
    Person p4 = 10; // Person p4 = Person(10);
    Person p5 = p4; // Person p5 = Person(p4);
    //注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
    //Person p5(p4);
}
int main7() {
    test01();
    //test02();
    system("pause");
    return 0;
}



// #### 4.2.3 拷贝构造函数调用时机
// C++中拷贝构造函数调用时机通常有三种情况
// * 使用一个已经创建完毕的对象来初始化一个新对象
// * 值传递的方式给函数参数传值
// * 以值方式返回局部对象
class Person {
public:
    Person() {
        cout << "无参构造函数!" << endl;
        mAge = 0;
    }
    Person(int age) {
        cout << "有参构造函数!" << endl;
        mAge = age;
    }
    Person(const Person& p) {
        cout << "拷贝构造函数!" << endl;
        mAge = p.mAge;
    }
    //析构函数在释放内存之前调用
    ~Person() {
        cout << "析构函数!" << endl;
    }
public:
    int mAge;
};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01() {

    Person man(100); //p对象已经创建完毕
    Person newman(man); //调用拷贝构造函数
    Person newman2 = man; //拷贝构造

    //Person newman3;
    //newman3 = man; //不是调用拷贝构造函数，赋值操作
}
//2. 值传递的方式给函数参数传值
//相当于Person p1 = p;
void doWork(Person p1) {}
void test02() {
    Person p; //无参构造函数
    doWork(p);
}
//3. 以值方式返回局部对象
Person doWork2()
{
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}
void test03()
{
    Person p = doWork2();
    cout << (int *)&p << endl;
}
int main8() {
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}

// #### 4.2.4 构造函数调用规则
// 默认情况下，c++编译器至少给一个类添加3个函数
// 1．默认构造函数(无参，函数体为空)
// 2．默认析构函数(无参，函数体为空)
// 3．默认拷贝构造函数，对属性进行值拷贝
// 构造函数调用规则如下：
// * 如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
// * 如果用户定义拷贝构造函数，c++不会再提供其他构造函数
class Person {
public:
    //无参（默认）构造函数
    Person() {
        cout << "无参构造函数!" << endl;
    }
    //有参构造函数
    Person(int a) {
        age = a;
        cout << "有参构造函数!" << endl;
    }
    //拷贝构造函数
    Person(const Person& p) {
        age = p.age;
        cout << "拷贝构造函数!" << endl;
    }
    //析构函数
    ~Person() {
        cout << "析构函数!" << endl;
    }
public:
    int age;
};
void test01()
{
    Person p1(18);
    //如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
    Person p2(p1);
    cout << "p2的年龄为： " << p2.age << endl;
}
void test02()
{
    //如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
    Person p1; //此时如果用户自己没有提供默认构造，会出错
    Person p2(10); //用户提供的有参
    Person p3(p2); //此时如果用户没有提供拷贝构造，编译器会提供
    //如果用户提供拷贝构造，编译器不会提供其他构造函数
    Person p4; //此时如果用户自己没有提供默认构造，会出错
    Person p5(10); //此时如果用户自己没有提供有参，会出错
    Person p6(p5); //用户自己提供拷贝构造
}
int main() {
    test01();
    system("pause");
    return 0;
}

// #### 4.2.5 深拷贝与浅拷贝
// 深浅拷贝是面试经典问题，也是常见的一个坑
// 浅拷贝：简单的赋值拷贝操作  会出现内存重复释放
// 深拷贝：在堆区重新申请空间，进行拷贝操作
class Person {
public:
    //无参（默认）构造函数
    Person() {
        cout << "无参构造函数!" << endl;
    }
    //有参构造函数
    Person(int age ,int height) {

        cout << "有参构造函数!" << endl;

        m_age = age;
        m_height = new int(height);
    }
    //拷贝构造函数
    Person(const Person& p) {
        cout << "拷贝构造函数!" << endl;
        //如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
        m_age = p.m_age;
        m_height = new int(*p.m_height);

    }
    //析构函数
    ~Person() {
        cout << "析构函数!" << endl;
        if (m_height != NULL)
        {
            delete m_height;
        }
    }
public:
    int m_age;
    int* m_height;
};
void test01()
{
    Person p1(18, 180);
    Person p2(p1);
    cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
    cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}


// #### 4.2.6 初始化列表
// **作用：**
// C++提供了初始化列表语法，用来初始化属性
// **语法：**`构造函数()：属性1(值1),属性2（值2）... {}`
class Person {
public:
    ////传统方式初始化
    //Person(int a, int b, int c) {
    //	m_A = a;
    //	m_B = b;
    //	m_C = c;
    //}
    //初始化列表方式初始化
    Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
    void PrintPerson() {
        cout << "mA:" << m_A << endl;
        cout << "mB:" << m_B << endl;
        cout << "mC:" << m_C << endl;
    }
private:
    int m_A;
    int m_B;
    int m_C;
};
int main9() {
    Person p(1, 2, 3);
    p.PrintPerson();
    system("pause");
    return 0;
}
// #### 4.2.7 类对象作为类成员
// C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员
class Phone
{
public:
    Phone(string name)
    {
        m_PhoneName = name;
        cout << "Phone构造" << endl;
    }
    ~Phone()
    {
        cout << "Phone析构" << endl;
    }
    string m_PhoneName;

};
class Person
{
public:
    //初始化列表可以告诉编译器调用哪一个构造函数
    Person(string name, string pName) :m_Name(name), m_Phone(pName)
    {
        cout << "Person构造" << endl;
    }
    ~Person()
    {
        cout << "Person析构" << endl;
    }
    void playGame()
    {
        cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
    }
    string m_Name;
    Phone m_Phone;
};
void test01()
{
    //当类中成员是其他类对象时，我们称该成员为 对象成员
    //构造的顺序是 ：先调用对象成员的构造，再调用本类构造
    //析构顺序与构造相反
    Person p("张三" , "苹果X");
    p.playGame();
}
int main10() {
    test01();
    system("pause");
    return 0;
}


// #### 4.2.8 静态成员
// 静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
// 静态成员分为：
// *  静态成员变量
//    *  所有对象共享同一份数据
//    *  在编译阶段分配内存
//    *  类内声明，类外初始化
// *  静态成员函数
//    *  所有对象共享同一个函数
//    *  静态成员函数只能访问静态成员变量
class Person
{
public:
    static int m_A; //静态成员变量
    //静态成员变量特点：
    //1 在编译阶段分配内存
    //2 类内声明，类外初始化
    //3 所有对象共享同一份数据
private:
    static int m_B; //静态成员变量也是有访问权限的
};
int Person::m_A = 10;//::说明是Person里的静态成员变量
int Person::m_B = 10;
void test01()
{
    //静态成员变量不属于任何一个对象,所有对象公用一个数据
    //静态成员变量两种访问方式
    //1、通过对象
    Person p1;
    p1.m_A = 100;
    cout << "p1.m_A = " << p1.m_A << endl;
    Person p2;
    p2.m_A = 200;
    cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
    cout << "p2.m_A = " << p2.m_A << endl;
    //2、通过类名
    cout << "m_A = " << Person::m_A << endl;
    //cout << "m_B = " << Person::m_B << endl; //私有权限访问不到
}
//静态成员函数
int main() {
    test01();
    system("pause");
    return 0;
}
class Person
{
public:
    //静态成员函数特点：
    //1 程序共享一个函数
    //2 静态成员函数只能访问静态成员变量
    static void func()
    {
        cout << "func调用" << endl;
        m_A = 100;
        //m_B = 100; //错误，不可以访问非静态成员变量 无法区分是哪个类的成员变量
    }
    static int m_A; //静态成员变量
    int m_B; //
private:
    //静态成员函数也是有访问权限的
    static void func2()
    {
        cout << "func2调用" << endl;
    }
};
int Person::m_A = 10;
void test01()
{
    //静态成员变量两种访问方式
    //1、通过对象
    Person p1;
    p1.func();
    //2、通过类名
    Person::func()
    //Person::func2(); //私有权限访问不到
}
int main() {
    test01();
    system("pause");
    return 0;
}