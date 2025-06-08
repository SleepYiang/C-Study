// ## 1 ģ��
// ### 1.1 ģ��ĸ���
// ģ����ǽ���**ͨ�õ�ģ��**�����**��߸�����**

// ģ����ص㣺
// * ģ�岻����ֱ��ʹ�ã���ֻ��һ�����
// * ģ���ͨ�ò��������ܵ�

// ### 1.2 ����ģ��
// * C++��һ�ֱ��˼���Ϊ ==���ͱ��== ����Ҫ���õļ�������ģ��
// * C++�ṩ����ģ�����:**����ģ��**��**��ģ��**
// #### 1.2.1 ����ģ���﷨
// ����ģ�����ã�
// ����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ�����һ��**���������**������
// **�﷨��**

// template<typename T>
// ������������
// **���ͣ�**
// template  ---  ��������ģ��
// typename  --- ���������ķ�����һ���������ͣ�������class����
// T    ---   ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
//�������ͺ���
void swapInt(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
//���������ͺ���
void swapDouble(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}
//����ģ���ṩͨ�õĽ�������
template<typename T>
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
void test01()
{
    int a = 10;
    int b = 20;
    //swapInt(a, b);
    //����ģ��ʵ�ֽ���
    //1���Զ������Ƶ�
    mySwap(a, b);
    //2����ʾָ������
    mySwap<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺
// * ����ģ�����ùؼ��� template
// * ʹ�ú���ģ�������ַ�ʽ���Զ������Ƶ�����ʾָ������
// * ģ���Ŀ����Ϊ����߸����ԣ������Ͳ�����


// #### 1.2.2 ����ģ��ע������
// ע�����
// * �Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
// * ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
//����ģ���ṩͨ�õĽ�������
template<class T>
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
// 1���Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    mySwap(a, b); // ��ȷ�������Ƶ���һ�µ�T
    //mySwap(a, c); // �����Ƶ�����һ�µ�T����
}
// 2��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func()
{
    cout << "func ����" << endl;
}
void test02()
{
    //func(); //����ģ�岻�ܶ���ʹ�ã�����ȷ����T������
    func<int>(); //������ʾָ�����͵ķ�ʽ����Tһ�����ͣ��ſ���ʹ�ø�ģ��
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}


// #### 1.2.4 ��ͨ�����뺯��ģ�������
// **��ͨ�����뺯��ģ������**
// * ��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
// * ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
// * ���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
//��ͨ����
int myAdd01(int a, int b)
{
    return a + b;
}
//����ģ��
template<class T>
T myAdd02(T a, T b)
{
    return a + b;
}
//ʹ�ú���ģ��ʱ��������Զ������Ƶ������ᷢ���Զ�����ת��,����ʽ����ת��
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myAdd01(a, c) << endl; //��ȷ����char���͵�'c'��ʽת��Ϊint����  'c' ��Ӧ ASCII�� 99
    //myAdd02(a, c); // ����ʹ���Զ������Ƶ�ʱ�����ᷢ����ʽ����ת��
    myAdd02<int>(a, c); //��ȷ���������ʾָ�����ͣ����Է�����ʽ����ת��
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺����ʹ����ʾָ�����͵ķ�ʽ�����ú���ģ�壬��Ϊ�����Լ�ȷ��ͨ������T


// #### 1.2.5 ��ͨ�����뺯��ģ��ĵ��ù���
// ���ù������£�
// 1. �������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
// 2. ����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
// 3. ����ģ��Ҳ���Է�������
// 4. �������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��
//��ͨ�����뺯��ģ����ù���
void myPrint(int a, int b)
{
    cout << "���õ���ͨ����" << endl;
}
template<typename T>
void myPrint(T a, T b)
{
    cout << "���õ�ģ��" << endl;
}
template<typename T>
void myPrint(T a, T b, T c)
{
    cout << "�������ص�ģ��" << endl;
}
void test01()
{
    //1���������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
    // ע�� ������߱�����  ��ͨ�������еģ���ֻ������û��ʵ�֣����߲��ڵ�ǰ�ļ���ʵ�֣��ͻᱨ���Ҳ���
    int a = 10;
    int b = 20;
    myPrint(a, b); //������ͨ����
    //2������ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
    myPrint<>(a, b); //���ú���ģ��
    //3������ģ��Ҳ���Է�������
    int c = 30;
    myPrint(a, b, c); //�������صĺ���ģ��
    //4�� �������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2); //���ú���ģ��
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺��Ȼ�ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ�����


// #### 1.2.6 ģ��ľ�����
// **�����ԣ�**
// * ģ���ͨ���Բ��������ܵ�
//�ض����������;���Ҫ�ض�����ʵ��
#include<iostream>
using namespace std;
#include <string>
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
//��ͨ����ģ��
template<class T>
bool myCompare(T& a, T& b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//���廯����ʾ���廯��ԭ�ͺͶ���˼��template<>��ͷ����ͨ��������ָ������
//���廯�����ڳ���ģ��
template<> bool myCompare(Person &p1, Person &p2)
{
    if ( p1.m_Name  == p2.m_Name && p1.m_Age == p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test01()
{
    int a = 10;
    int b = 20;
    //�����������Ϳ���ֱ��ʹ��ͨ�õĺ���ģ��
    bool ret = myCompare(a, b);
    if (ret)
    {
        cout << "a == b " << endl;
    }
    else
    {
        cout << "a != b " << endl;
    }
}
void test02()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    //�Զ����������ͣ����������ͨ�ĺ���ģ��
    //���Դ������廯��Person�������͵�ģ�壬�������⴦���������
    bool ret = myCompare(p1, p2);
    if (ret)
    {
        cout << "p1 == p2 " << endl;
    }
    else
    {
        cout << "p1 != p2 " << endl;
    }
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
// �ܽ᣺
// * ���þ��廯��ģ�壬���Խ���Զ������͵�ͨ�û�
// * ѧϰģ�岢����Ϊ��дģ�壬������STL�ܹ�����ϵͳ�ṩ��ģ��

// ### 1.3 ��ģ��
// #### 1.3.1 ��ģ���﷨
// ��ģ�����ã�
// * ����һ��ͨ���࣬���еĳ�Ա �������Ϳ��Բ������ƶ�����һ��**���������**������

// **���ͣ�**
// template  ---  ��������ģ��
// typename  --- ���������ķ�����һ���������ͣ�������class����
// T    ---   ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
#include <string>
//��ģ��
template<class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name: " << this->mName << " age: " << this->mAge << endl;
    }
public:
    NameType mName;
    AgeType mAge;
};
void test01()
{
    // ָ��NameType Ϊstring���ͣ�AgeType Ϊ int����
    Person<string, int>P1("�����", 999);
    P1.showPerson();
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺��ģ��ͺ���ģ���﷨���ƣ�������ģ��template������࣬�����Ϊ��ģ��

// #### 1.3.2 ��ģ���뺯��ģ������
// ��ģ���뺯��ģ��������Ҫ�����㣺
// 1. ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
// 2. ��ģ����ģ������б��п�����Ĭ�ϲ���
// �ܽ᣺
// * ��ģ��ʹ��ֻ������ʾָ�����ͷ�ʽ
// * ��ģ���е�ģ������б������Ĭ�ϲ���


// #### 1.3.3 ��ģ���г�Ա��������ʱ��
// ��ģ���г�Ա��������ͨ���г�Ա��������ʱ����������ģ�
// * ��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
// * ��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};
class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};
template<class T>
class MyClass
{
public:
    T obj;
    //��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������
    void fun1() { obj.showPerson1(); }
    void fun2() { obj.showPerson2(); }
};
void test01()
{
    MyClass<Person1> m;
    m.fun1();
    //m.fun2();//��������˵���������òŻ�ȥ������Ա����
}
int main() {
    test01();
    system("pause");
    return 0;
}

// #### 1.3.4 ��ģ���������������
// ѧϰĿ�꣺
// * ��ģ��ʵ�������Ķ����������εķ�ʽ
// һ�������ִ��뷽ʽ��
// 1. ָ�����������   --- ֱ����ʾ�������������
// 2. ����ģ�廯           --- �������еĲ�����Ϊģ����д���
// 3. ������ģ�廯       --- ������������� ģ�廯���д���
#include <string>
//��ģ��
template<class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name: " << this->mName << " age: " << this->mAge << endl;
    }
public:
    NameType mName;
    AgeType mAge;
};
//1��ָ�����������
void printPerson1(Person<string, int> &p)
{
    p.showPerson();
}
void test01()
{
    Person <string, int >p("�����", 100);
    printPerson1(p);
}
//2������ģ�廯
template <class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
    p.showPerson();
    cout << "T1������Ϊ�� " << typeid(T1).name() << endl;
    cout << "T2������Ϊ�� " << typeid(T2).name() << endl;
}
void test02()
{
    Person <string, int >p("��˽�", 90);
    printPerson2(p);
}
//3��������ģ�廯
template<class T>
void printPerson3(T & p)
{
    cout << "T������Ϊ�� " << typeid(T).name() << endl;
    p.showPerson();
}
void test03()
{
    Person <string, int >p("��ɮ", 30);
    printPerson3(p);
}
int main() {
    test01();
    test02();
    test03();
    system("pause");
    return 0;
}
// * ͨ����ģ�崴���Ķ��󣬿��������ַ�ʽ�����н��д���
// * ʹ�ñȽϹ㷺�ǵ�һ�֣�ָ�����������


// #### 1.3.5 ��ģ����̳�
// ����ģ�������̳�ʱ����Ҫע��һ�¼��㣺
// * ������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
// * �����ָ�����������޷�����������ڴ�
// * ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
template<class T>
class Base
{
    T m;
};
//class Son:public Base  //����c++������Ҫ����������ڴ棬����֪��������T�����Ͳſ������¼̳�
class Son :public Base<int> //����ָ��һ������
{
};
void test01()
{
    Son c;
}
//��ģ��̳���ģ�� ,������T2ָ�������е�T����
template<class T1, class T2>
class Son2 :public Base<T2>
{
public:
    Son2()
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
};
void test02()
{
    Son2<int, char> child1;
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}

// #### 1.3.6 ��ģ���Ա��������ʵ��
// ѧϰĿ�꣺�ܹ�������ģ���еĳ�Ա��������ʵ��
#include <string>
//��ģ���г�Ա��������ʵ��
template<class T1, class T2>
class Person {
public:
    //��Ա������������
    Person(T1 name, T2 age);
    void showPerson();
public:
    T1 m_Name;
    T2 m_Age;
};
//���캯�� ����ʵ��
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
}
//��Ա���� ����ʵ��
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
    cout << "����: " << this->m_Name << " ����:" << this->m_Age << endl;
}
void test01()
{
    Person<string, int> p("Tom", 20);
    p.showPerson();
}
int main() {
    test01();
    system("pause");
    return 0;
}

// #### 1.3.7 ��ģ����ļ���д
// ѧϰĿ�꣺
// * ������ģ���Ա�������ļ���д�����������Լ������ʽ
// ���⣺
// * ��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
// �����
// * �����ʽ1��ֱ�Ӱ���.cppԴ�ļ�
// * �����ʽ2����������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��
// �ܽ᣺�����Ľ����ʽ�ǵڶ��֣�����ģ���Ա����д��һ�𣬲�����׺����Ϊ.hpp

