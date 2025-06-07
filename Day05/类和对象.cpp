// ## **4** ��Ͷ���
// C++����������������Ϊ��==��װ���̳С���̬==
// C++��Ϊ==�������ﶼ��Ϊ����==���������������Ժ���Ϊ
// **���磺**
// �˿�����Ϊ�������������������䡢��ߡ�����...����Ϊ���ߡ��ܡ������Է�������...
// ��Ҳ������Ϊ������������̥�������̡�����...,��Ϊ�����ˡ������֡��ſյ�...
// ������ͬ���ʵ�==����==�����ǿ��Գ����Ϊ==��==�����������࣬�����ڳ���

// ### 4.1 ��װ
// #### 4.1.1  ��װ������
// ��װ��C++���������������֮һ
// ��װ�����壺
// * �����Ժ���Ϊ��Ϊһ�����壬���������е�����
// * �����Ժ���Ϊ����Ȩ�޿���
// **��װ����һ��**
// ��������ʱ�����Ժ���Ϊд��һ�𣬱�������
// **�﷨��** `class ����{   ����Ȩ�ޣ� ����  / ��Ϊ  };`
//ʾ��1
#include<iostream>
using namespace std;
const double PI = 3.14;
//1����װ������
//�����Ժ���Ϊ��Ϊһ�����壬�������������е�����
//��װһ��Բ�࣬��Բ���ܳ�
//class�������һ���࣬������ŵ�������
class Circle
{
public://����Ȩ��  ������Ȩ��
    //����
    int m_r;//�뾶
    //��Ϊ  (��ȡ��Բ���ܳ�)
    double calculateZC()
    {
        return m_r*2*PI;
    }
};
int main0()
{
    //ͨ��Բ�ഴ��Ԫ�Ķ���
    //c1����һ�������Բ
    Circle c1;
    c1.m_r = 10; //��Բ����İ뾶 ���и�ֵ����
    //2 * pi * 10 = = 62.8
    cout << "Բ���ܳ�Ϊ�� " << c1.calculateZC() << endl;
    system("pause");
    return 0;
}
//ʾ��2
//ѧ����
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
    stu.setName("��������");
    stu.setID(250);
    stu.showStudent();
    system("pause");
    return 0;
}
// **��װ�������**
// �������ʱ�����԰����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ���
// ����Ȩ�������֣�
// 1. public        ����Ȩ��
// 2. protected ����Ȩ��
// 3. private      ˽��Ȩ��
//����Ȩ��
//����Ȩ��  public     ���ڿ��Է���  ������Է���
//����Ȩ��  protected  ���ڿ��Է���  ���ⲻ���Է���
//˽��Ȩ��  private    ���ڿ��Է���  ���ⲻ���Է���

class Person01
{
    //����  ����Ȩ��
public:
    string m_Name;
    //����  ����Ȩ��
protected:
    string m_Car;
    //���п�����  ˽��Ȩ��
private:
    int m_Password;
public:
    void func()
    {
        m_Name = "����";
        m_Car = "������";
        m_Password = 123456;
    }
};
int main2() {
    Person01 p;
    p.m_Name = "����";
    //p.m_Car = "����";  //����Ȩ��������ʲ���
    //p.m_Password = 123; //˽��Ȩ��������ʲ���
    system("pause");
    return 0;
}


// #### 4.1.2 struct��class����
// ��C++�� struct��classΨһ��**����**������ **Ĭ�ϵķ���Ȩ�޲�ͬ**
// ����
// * struct Ĭ��Ȩ��Ϊ����
// * class   Ĭ��Ȩ��Ϊ˽��
class C1
{
    int  m_A; //Ĭ����˽��Ȩ��
};
struct C2
{
    int m_A;  //Ĭ���ǹ���Ȩ��
};
int main3() {
    C1 c1;
    c1.m_A = 10; //���󣬷���Ȩ����˽��
    C2 c2;
    c2.m_A = 10; //��ȷ������Ȩ���ǹ���
    system("pause");
    return 0;
}

// #### 4.1.3 ��Ա��������Ϊ˽��
// **�ŵ�1��**�����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
// **�ŵ�2��**����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
class Person {
public:
    //�������ÿɶ���д
    void setName(string name) {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }
    //��ȡ����
    int getAge() {
        return m_Age;
    }
    //��������
    void setAge(int age) {
        if (age < 0 || age > 150) {
            cout << "���������!" << endl;
            return;
        }
        m_Age = age;
    }
    //��������Ϊֻд
    void setLover(string lover) {
        m_Lover = lover;
    }
private:
    string m_Name; //�ɶ���д  ����
    int m_Age; //ֻ��  ����
    string m_Lover; //ֻд  ����
};
int main4() {
    Person p;
    //��������
    p.setName("����");
    cout << "������ " << p.getName() << endl;
    //��������
    p.setAge(50);
    cout << "���䣺 " << p.getAge() << endl;
    //��������
    p.setLover("�Ծ�");
    //cout << "���ˣ� " << p.m_Lover << endl;  //ֻд���ԣ������Զ�ȡ
    system("pause");
    return 0;
}

// ### 4.2 ����ĳ�ʼ��������
//������������ĵ��Ӳ�Ʒ���������г������ã���ĳһ�����ǲ���ʱ��Ҳ��ɾ��һЩ�Լ���Ϣ���ݱ�֤��ȫ
//C++�е����������Դ�����ÿ������Ҳ�����г�ʼ�����Լ� ��������ǰ���������ݵ����á�

// #### 4.2.1 ���캯������������
// �����**��ʼ��������**Ҳ�������ǳ���Ҫ�İ�ȫ����
//һ��������߱���û�г�ʼ״̬������ʹ�ú����δ֪
// ͬ����ʹ����һ������������û�м�ʱ����Ҳ�����һ���İ�ȫ����
// c++������**���캯��**��**��������**����������⣬�������������ᱻ�������Զ����ã���ɶ����ʼ������������
// ����ĳ�ʼ�����������Ǳ�����ǿ��Ҫ�����������飬������**���ǲ��ṩ��������������������ṩ**
// **�������ṩ�Ĺ��캯�������������ǿ�ʵ�֡�**

// * ���캯������Ҫ�������ڴ�������ʱΪ����ĳ�Ա���Ը�ֵ�����캯���ɱ������Զ����ã������ֶ����á�

// * ������������Ҫ�������ڶ���**����ǰ**ϵͳ�Զ����ã�ִ��һЩ��������

// **���캯���﷨��**`����(){}`
// 1. ���캯����û�з���ֵҲ��дvoid
// 2. ����������������ͬ
// 3. ���캯�������в�������˿��Է�������
// 4. �����ڵ��ö���ʱ����Զ����ù��죬�����ֶ�����,����ֻ�����һ��

// **���������﷨��** `~����(){}`
// 1. ����������û�з���ֵҲ��дvoid
// 2. ����������������ͬ,������ǰ���Ϸ���  ~
// 3. ���������������в�������˲����Է�������
// 4. �����ڶ�������ǰ���Զ����������������ֶ�����,����ֻ�����һ��
class Person
{
public:
    //���캯��
    Person()
    {
        cout << "Person�Ĺ��캯������" << endl;
    }
    //��������
    ~Person()
    {
        cout << "Person��������������" << endl;
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


// #### 4.2.2 ���캯���ķ��༰����
// ���ַ��෽ʽ��
//��������Ϊ�� �вι�����޲ι���
//�����ͷ�Ϊ�� ��ͨ����Ϳ�������
// ���ֵ��÷�ʽ��
//���ŷ�
//��ʾ��
//��ʽת����
//1�����캯������
// ���ղ��������Ϊ �вκ��޲ι���   �޲��ֳ�ΪĬ�Ϲ��캯��
// �������ͷ����Ϊ ��ͨ����Ϳ�������
class Person {
public:
    //�޲Σ�Ĭ�ϣ����캯��
    Person() {
        cout << "�޲ι��캯��!" << endl;
    }
    //�вι��캯��
    Person(int a) {
        age = a;
        cout << "�вι��캯��!" << endl;
    }
    //�������캯��
    Person(const Person& p) {
        age = p.age;
        cout << "�������캯��!" << endl;
    }
    //��������
    ~Person() {
        cout << "��������!" << endl;
    }
public:
    int age;
};
//2�����캯���ĵ���
//�����޲ι��캯��
void test01() {
    Person p; //�����޲ι��캯��
}
//�����вεĹ��캯��
void test02() {
    //2.1  ���ŷ�������
    Person p1(10);
    //ע��1�������޲ι��캯�����ܼ����ţ�������˱�������Ϊ����һ����������
    //Person p2();
    //2.2 ��ʽ��
    Person p2 = Person(10);
    Person p3 = Person(p2);
    //Person(10)����д������������  ��ǰ�н���֮����������
    //2.3 ��ʽת����
    Person p4 = 10; // Person p4 = Person(10);
    Person p5 = p4; // Person p5 = Person(p4);
    //ע��2���������� �������캯�� ��ʼ���������� ��������Ϊ�Ƕ�������
    //Person p5(p4);
}
int main7() {
    test01();
    //test02();
    system("pause");
    return 0;
}



// #### 4.2.3 �������캯������ʱ��
// C++�п������캯������ʱ��ͨ�����������
// * ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
// * ֵ���ݵķ�ʽ������������ֵ
// * ��ֵ��ʽ���ؾֲ�����
class Person {
public:
    Person() {
        cout << "�޲ι��캯��!" << endl;
        mAge = 0;
    }
    Person(int age) {
        cout << "�вι��캯��!" << endl;
        mAge = age;
    }
    Person(const Person& p) {
        cout << "�������캯��!" << endl;
        mAge = p.mAge;
    }
    //�����������ͷ��ڴ�֮ǰ����
    ~Person() {
        cout << "��������!" << endl;
    }
public:
    int mAge;
};

//1. ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01() {

    Person man(100); //p�����Ѿ��������
    Person newman(man); //���ÿ������캯��
    Person newman2 = man; //��������

    //Person newman3;
    //newman3 = man; //���ǵ��ÿ������캯������ֵ����
}
//2. ֵ���ݵķ�ʽ������������ֵ
//�൱��Person p1 = p;
void doWork(Person p1) {}
void test02() {
    Person p; //�޲ι��캯��
    doWork(p);
}
//3. ��ֵ��ʽ���ؾֲ�����
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

// #### 4.2.4 ���캯�����ù���
// Ĭ������£�c++���������ٸ�һ�������3������
// 1��Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)
// 2��Ĭ����������(�޲Σ�������Ϊ��)
// 3��Ĭ�Ͽ������캯���������Խ���ֵ����
// ���캯�����ù������£�
// * ����û������вι��캯����c++�����ṩĬ���޲ι��죬���ǻ��ṩĬ�Ͽ�������
// * ����û����忽�����캯����c++�������ṩ�������캯��
class Person {
public:
    //�޲Σ�Ĭ�ϣ����캯��
    Person() {
        cout << "�޲ι��캯��!" << endl;
    }
    //�вι��캯��
    Person(int a) {
        age = a;
        cout << "�вι��캯��!" << endl;
    }
    //�������캯��
    Person(const Person& p) {
        age = p.age;
        cout << "�������캯��!" << endl;
    }
    //��������
    ~Person() {
        cout << "��������!" << endl;
    }
public:
    int age;
};
void test01()
{
    Person p1(18);
    //�����д�������죬���������Զ���ӿ������죬������ǳ��������
    Person p2(p1);
    cout << "p2������Ϊ�� " << p2.age << endl;
}
void test02()
{
    //����û��ṩ�вι��죬�����������ṩĬ�Ϲ��죬���ṩ��������
    Person p1; //��ʱ����û��Լ�û���ṩĬ�Ϲ��죬�����
    Person p2(10); //�û��ṩ���в�
    Person p3(p2); //��ʱ����û�û���ṩ�������죬���������ṩ
    //����û��ṩ�������죬�����������ṩ�������캯��
    Person p4; //��ʱ����û��Լ�û���ṩĬ�Ϲ��죬�����
    Person p5(10); //��ʱ����û��Լ�û���ṩ�вΣ������
    Person p6(p5); //�û��Լ��ṩ��������
}
int main() {
    test01();
    system("pause");
    return 0;
}

// #### 4.2.5 �����ǳ����
// ��ǳ���������Ծ������⣬Ҳ�ǳ�����һ����
// ǳ�������򵥵ĸ�ֵ��������  ������ڴ��ظ��ͷ�
// ������ڶ�����������ռ䣬���п�������
class Person {
public:
    //�޲Σ�Ĭ�ϣ����캯��
    Person() {
        cout << "�޲ι��캯��!" << endl;
    }
    //�вι��캯��
    Person(int age ,int height) {

        cout << "�вι��캯��!" << endl;

        m_age = age;
        m_height = new int(height);
    }
    //�������캯��
    Person(const Person& p) {
        cout << "�������캯��!" << endl;
        //�������������ڶ����������ڴ棬�ᵼ��ǳ�����������ظ��ͷŶ�������
        m_age = p.m_age;
        m_height = new int(*p.m_height);

    }
    //��������
    ~Person() {
        cout << "��������!" << endl;
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
    cout << "p1�����䣺 " << p1.m_age << " ��ߣ� " << *p1.m_height << endl;
    cout << "p2�����䣺 " << p2.m_age << " ��ߣ� " << *p2.m_height << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}


// #### 4.2.6 ��ʼ���б�
// **���ã�**
// C++�ṩ�˳�ʼ���б��﷨��������ʼ������
// **�﷨��**`���캯��()������1(ֵ1),����2��ֵ2��... {}`
class Person {
public:
    ////��ͳ��ʽ��ʼ��
    //Person(int a, int b, int c) {
    //	m_A = a;
    //	m_B = b;
    //	m_C = c;
    //}
    //��ʼ���б�ʽ��ʼ��
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
// #### 4.2.7 �������Ϊ���Ա
// C++���еĳ�Ա��������һ����Ķ������ǳƸó�ԱΪ �����Ա
class Phone
{
public:
    Phone(string name)
    {
        m_PhoneName = name;
        cout << "Phone����" << endl;
    }
    ~Phone()
    {
        cout << "Phone����" << endl;
    }
    string m_PhoneName;

};
class Person
{
public:
    //��ʼ���б���Ը��߱�����������һ�����캯��
    Person(string name, string pName) :m_Name(name), m_Phone(pName)
    {
        cout << "Person����" << endl;
    }
    ~Person()
    {
        cout << "Person����" << endl;
    }
    void playGame()
    {
        cout << m_Name << " ʹ��" << m_Phone.m_PhoneName << " ���ֻ�! " << endl;
    }
    string m_Name;
    Phone m_Phone;
};
void test01()
{
    //�����г�Ա�����������ʱ�����ǳƸó�ԱΪ �����Ա
    //�����˳���� ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
    //����˳���빹���෴
    Person p("����" , "ƻ��X");
    p.playGame();
}
int main10() {
    test01();
    system("pause");
    return 0;
}


// #### 4.2.8 ��̬��Ա
// ��̬��Ա�����ڳ�Ա�����ͳ�Ա����ǰ���Ϲؼ���static����Ϊ��̬��Ա
// ��̬��Ա��Ϊ��
// *  ��̬��Ա����
//    *  ���ж�����ͬһ������
//    *  �ڱ���׶η����ڴ�
//    *  ���������������ʼ��
// *  ��̬��Ա����
//    *  ���ж�����ͬһ������
//    *  ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class Person
{
public:
    static int m_A; //��̬��Ա����
    //��̬��Ա�����ص㣺
    //1 �ڱ���׶η����ڴ�
    //2 ���������������ʼ��
    //3 ���ж�����ͬһ������
private:
    static int m_B; //��̬��Ա����Ҳ���з���Ȩ�޵�
};
int Person::m_A = 10;//::˵����Person��ľ�̬��Ա����
int Person::m_B = 10;
void test01()
{
    //��̬��Ա�����������κ�һ������,���ж�����һ������
    //��̬��Ա�������ַ��ʷ�ʽ
    //1��ͨ������
    Person p1;
    p1.m_A = 100;
    cout << "p1.m_A = " << p1.m_A << endl;
    Person p2;
    p2.m_A = 200;
    cout << "p1.m_A = " << p1.m_A << endl; //����ͬһ������
    cout << "p2.m_A = " << p2.m_A << endl;
    //2��ͨ������
    cout << "m_A = " << Person::m_A << endl;
    //cout << "m_B = " << Person::m_B << endl; //˽��Ȩ�޷��ʲ���
}
//��̬��Ա����
int main() {
    test01();
    system("pause");
    return 0;
}
class Person
{
public:
    //��̬��Ա�����ص㣺
    //1 ������һ������
    //2 ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
    static void func()
    {
        cout << "func����" << endl;
        m_A = 100;
        //m_B = 100; //���󣬲����Է��ʷǾ�̬��Ա���� �޷��������ĸ���ĳ�Ա����
    }
    static int m_A; //��̬��Ա����
    int m_B; //
private:
    //��̬��Ա����Ҳ���з���Ȩ�޵�
    static void func2()
    {
        cout << "func2����" << endl;
    }
};
int Person::m_A = 10;
void test01()
{
    //��̬��Ա�������ַ��ʷ�ʽ
    //1��ͨ������
    Person p1;
    p1.func();
    //2��ͨ������
    Person::func()
    //Person::func2(); //˽��Ȩ�޷��ʲ���
}
int main() {
    test01();
    system("pause");
    return 0;
}