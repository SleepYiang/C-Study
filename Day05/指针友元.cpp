// ### 4.3 C++对象模型和this指针
// #### 4.3.1 成员变量和成员函数分开存储
// 在C++中，类内的成员变量和成员函数分开存储
// 只有非静态成员变量才属于类的对象上
#include<iostream>
using namespace std;
class Person {
public:
    Person() {
        mA = 0;
    }
    //非静态成员变量占对象空间
    int mA;
    //静态成员变量不占对象空间
    static int mB;
    //函数也不占对象空间，所有函数共享一个函数实例
    void func() {
        cout << "mA:" << this->mA << endl;
    }
    //静态成员函数也不占对象空间
    static void sfunc() {
    }
};
int main0() {
    cout << sizeof(Person) << endl;
    system("pause");
    return 0;
}


// #### 4.3.2 this指针概念
// 通过4.3.1我们知道在C++中成员变量和成员函数是分开存储的
// 每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
// 那么问题是：这一块代码是如何区分那个对象调用自己的呢？
// c++通过提供特殊的对象指针，this指针，解决上述问题。**this指针指向被调用的成员函数所属的对象**
// this指针是隐含每一个非静态成员函数内的一种指针
// this指针不需要定义，直接使用即可
// this指针的用途：
// *  当形参和成员变量同名时，可用this指针来区分
// *  在类的非静态成员函数中返回对象本身，可使用return *this
class Person
{
public:
    Person(int age)
    {
        //1、当形参和成员变量同名时，可用this指针来区分
        this->age = age;
    }
    Person& PersonAddPerson(Person p)
    {
        this->age += p.age;
        //返回对象本身
        return *this;
    }
    int age;
};
void test01()
{
    Person p1(10);
    cout << "p1.age = " << p1.age << endl;
    Person p2(10);
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "p2.age = " << p2.age << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}


// #### 4.3.3 空指针访问成员函数
// C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
// 如果用到this指针，需要加以判断保证代码的健壮性
//空指针访问成员函数
class Person {
public:
    void ShowClassName() {
        cout << "我是Person类!" << endl;
    }
    void ShowPerson() {
        if (this == NULL) {
            return;
        }
        cout << mAge << endl;
    }
public:
    int mAge;
};
void test01()
{
    Person * p = NULL;
    p->ShowClassName(); //空指针，可以调用成员函数
    p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了
}
int main() {
    test01();
    system("pause");
    return 0;
}

// #### 4.3.4 const修饰成员函数
// **常函数：**
// * 成员函数后加const后我们称为这个函数为**常函数**
// * 常函数内不可以修改成员属性
// * 成员属性声明时加关键字mutable后，在常函数中依然可以修改
// **常对象：**
// * 声明对象前加const称该对象为常对象
// * 常对象只能调用常函数
class Person {
public:
    Person() {
        m_A = 0;
        m_B = 0;
    }
    //this指针的本质是一个指针常量，指针的指向不可修改
    //如果想让指针指向的值也不可以修改，需要声明常函数
    void ShowPerson() const {
        //const Type* const pointer;
        //this = NULL; //不能修改指针的指向 Person* const this;
        //this->mA = 100; //但是this指针指向的对象的数据是可以修改的
        //const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
        this->m_B = 100;
    }
    void MyFunc() const {
        //mA = 10000;
    }
public:
    int m_A;
    mutable int m_B; //可修改 可变的
};
//const修饰对象  常对象
void test01() {
    const Person person; //常量对象
    cout << person.m_A << endl;
    //person.mA = 100; //常对象不能修改成员变量的值,但是可以访问
    person.m_B = 100; //但是常对象可以修改mutable修饰成员变量
    //常对象访问成员函数
    person.MyFunc(); //常对象不能调用const的函数
}
int main3() {
    test01();
    system("pause");
    return 0;
}

// ### 4.4 友元
// 生活中你的家有客厅(Public)，有你的卧室(Private)
// 客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去
// 但是呢，你也可以允许你的好闺蜜好基友进去。
// 在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
// 友元的目的就是让一个函数或者类 访问另一个类中私有成员
// 友元的关键字为  ==friend==

// 友元的三种实现
// * 全局函数做友元
// * 类做友元
// * 成员函数做友元

//全局函数做友元
class Building
{
    //告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容
    friend void goodGay(Building * building);
public:
    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }
public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom; //卧室
};
void goodGay(Building * building)
{
    cout << "好基友正在访问： " << building->m_SittingRoom << endl;
    cout << "好基友正在访问： " << building->m_BedRoom << endl;
}
void test01()
{
    Building b;
    goodGay(&b);
}
int main4(){
    test01();
    system("pause");
    return 0;
}

//类做友元
class Building;
class goodGay
{
public:
    goodGay();
    void visit(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容
    void visit2();

private:
    Building *building;
};

class Building
{
    //告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
    friend void goodGay::visit();

public:
    Building();
public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom;//卧室
};
Building::Building()
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}
goodGay::goodGay()
{
    building = new Building;
}
void goodGay::visit()
{
    cout << "好基友正在访问" << building->m_SittingRoom << endl;
    cout << "好基友正在访问" << building->m_BedRoom << endl;
}
void goodGay::visit2()
{
    cout << "好基友正在访问" << building->m_SittingRoom << endl;
    //cout << "好基友正在访问" << building->m_BedRoom << endl;
}
void test01()
{
    goodGay  gg;
    gg.visit();
}
int main(){
    test01();
    system("pause");
    return 0;
}
// ### 4.5 运算符重载
// 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
// #### 4.5.1 加号运算符重载
// 作用：实现两个自定义数据类型相加的运算
class Person {
public:
    Person() {};
    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }
    //成员函数实现 + 号运算符重载
    Person operator+(const Person& p) {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }


public:
    int m_A;
    int m_B;
};

//全局函数实现 + 号运算符重载
//Person operator+(const Person& p1, const Person& p2) {
//	Person temp(0, 0);
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

//运算符重载 可以发生函数重载
Person operator+(const Person& p2, int val)
{
    Person temp;
    temp.m_A = p2.m_A + val;
    temp.m_B = p2.m_B + val;
    return temp;
}
void test() {
    Person p1(10, 10);
    Person p2(20, 20);
    //成员函数方式
    Person p3 = p2 + p1;  //相当于 p2.operaor+(p1)
    cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;
    Person p4 = p3 + 10; //相当于 operator+(p3,10)
    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
}
int main6() {
    test();
    system("pause");
    return 0;
}
// 4.5.2 左移运算符重载
class Person {
    friend ostream& operator<<(ostream& out, Person& p);
public:
    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }
    //成员函数 实现不了  p << cout 不是我们想要的效果
    //void operator<<(Person& p){
    //}
private:
    int m_A;
    int m_B;
};
//全局函数实现左移重载
//ostream对象只能有一个

//递增重载
ostream& operator<<(ostream& out, Person& p) {
    out << "a:" << p.m_A << " b:" << p.m_B;
    return out;
}
void test() {
    Person p1(10, 20);
    cout << p1 << "hello world" << endl; //链式编程
}
int main() {
    test();
    system("pause");
    return 0;
}
class Person {
    friend ostream& operator<<(ostream& out, Person& p);
public:
    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }
    //成员函数 实现不了  p << cout 不是我们想要的效果
    //void operator<<(Person& p){
    //}
private:
    int m_A;
    int m_B;
};
//全局函数实现左移重载
//ostream对象只能有一个
ostream& operator<<(ostream& out, Person& p) {
    out << "a:" << p.m_A << " b:" << p.m_B;
    return out;
}
void test() {
    Person p1(10, 20);
    cout << p1 << "hello world" << endl; //链式编程
}
int main() {
    test();
    system("pause");
    return 0;
}


// #### 4.5.4 赋值运算符重载
// c++编译器至少给一个类添加4个函数
// 1. 默认构造函数(无参，函数体为空)
// 2. 默认析构函数(无参，函数体为空)
// 3. 默认拷贝构造函数，对属性进行值拷贝
// 4. 赋值运算符 operator=, 对属性进行值拷贝
// 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
class Person
{
public:
    Person(int age)
    {
        //将年龄数据开辟到堆区
        m_Age = new int(age);
    }
    //重载赋值运算符
    Person& operator=(Person &p)
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        //编译器提供的代码是浅拷贝
        //m_Age = p.m_Age;
        //提供深拷贝 解决浅拷贝的问题
        m_Age = new int(*p.m_Age);
        //返回自身
        return *this;
    }
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
    //年龄的指针
    int *m_Age;
};
void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1; //赋值操作
    cout << "p1的年龄为：" << *p1.m_Age << endl;
    cout << "p2的年龄为：" << *p2.m_Age << endl;
    cout << "p3的年龄为：" << *p3.m_Age << endl;
}
int main() {
    test01();
    //int a = 10;
    //int b = 20;
    //int c = 30;
    //c = b = a;
    //cout << "a = " << a << endl;
    //cout << "b = " << b << endl;
    //cout << "c = " << c << endl;
    system("pause");
    return 0;
}



//关系运算符
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    };
    bool operator==(Person & p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(Person & p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    string m_Name;
    int m_Age;
};
void test01()
{
    //int a = 0;
    //int b = 0;
    Person a("孙悟空", 18);
    Person b("孙悟空", 18);
    if (a == b)
    {
        cout << "a和b相等" << endl;
    }
    else
    {
        cout << "a和b不相等" << endl;
    }
    if (a != b)
    {
        cout << "a和b不相等" << endl;
    }
    else
    {
        cout << "a和b相等" << endl;
    }
}
int main() {
    test01();
    system("pause");
    return 0;
}
// #### 4.5.6 函数调用运算符重载
// * 函数调用运算符 ()  也可以重载
// * 由于重载后使用的方式非常像函数的调用，因此称为仿函数
// * 仿函数没有固定写法，非常灵活
class MyPrint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};
void test01()
{
    //重载的（）操作符 也称为仿函数
    MyPrint myFunc;
    myFunc("hello world");
}
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};
void test02()
{
    MyAdd add;
    int ret = add(10, 10);
    cout << "ret = " << ret << endl;
    //匿名对象调用
    cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}