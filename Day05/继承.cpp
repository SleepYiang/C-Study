// #### 4.6.1 �̳еĻ����﷨
// �������ǿ����ܶ���վ�У����й�����ͷ���������ĵײ�����������������б�ֻ���������ݲ�ͬ
// ���������Ƿֱ�������ͨд���ͼ̳е�д����ʵ����ҳ�е����ݣ���һ�¼̳д��ڵ������Լ��ô�
#include<iostream>
using namespace std;
//��ͨ�Ľ���ʵ��
//Javaҳ��
class Java
{
public:
    void header()
    {
        cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
    }

    void footer()
    {
        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
    }

    void left()
    {
        cout << "Java,Python,C++...(���������б�)" << endl;
    }

    void content()
    {
        cout << "JAVAѧ����Ƶ" << endl;
    }
};

//Pythonҳ��
class Python
{
public:
    void header()
    {
        cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
    }

    void footer()
    {
        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
    }

    void left()
    {
        cout << "Java,Python,C++...(���������б�)" << endl;
    }

    void content()
    {
        cout << "Pythonѧ����Ƶ" << endl;
    }
};

//C++ҳ��
class CPP
{
public:
    void header()
    {
        cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
    }

    void footer()
    {
        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
    }

    void left()
    {
        cout << "Java,Python,C++...(���������б�)" << endl;
    }

    void content()
    {
        cout << "C++ѧ����Ƶ" << endl;
    }
};

void test01()
{
    //Javaҳ��
    cout << "Java������Ƶҳ�����£� " << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "--------------------" << endl;
    //Pythonҳ��
    cout << "Python������Ƶҳ�����£� " << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "--------------------" << endl;
    //C++ҳ��
    cout << "C++������Ƶҳ�����£� " << endl;
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

//�̳еĽ���ʵ��
//����ҳ��
class BasePage
{
public:
    void header()
    {
        cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
    }

    void footer()
    {
        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
    }

    void left()
    {
        cout << "Java,Python,C++...(���������б�)" << endl;
    }
};

//Javaҳ��
class Java : public BasePage
{
public:
    void content()
    {
        cout << "JAVAѧ����Ƶ" << endl;
    }
};

//Pythonҳ��
class Python : public BasePage
{
public:
    void content()
    {
        cout << "Pythonѧ����Ƶ" << endl;
    }
};

//C++ҳ��
class CPP : public BasePage
{
public:
    void content()
    {
        cout << "C++ѧ����Ƶ" << endl;
    }
};

void test01()
{
    //Javaҳ��
    cout << "Java������Ƶҳ�����£� " << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "--------------------" << endl;
    //Pythonҳ��
    cout << "Python������Ƶҳ�����£� " << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "--------------------" << endl;
    //C++ҳ��
    cout << "C++������Ƶҳ�����£� " << endl;
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

//**�ܽ᣺**
// �̳еĺô���==���Լ����ظ��Ĵ���==
// class A : public B;
// A ���Ϊ���� �� ������
// B ���Ϊ���� �� ����
// **�������еĳ�Ա���������󲿷�**��
// һ���Ǵӻ���̳й����ģ�һ�����Լ����ӵĳ�Ա��
// �ӻ���̳й������ı����乲�ԣ��������ĳ�Ա����������ԡ�

//#### 4.6.2 �̳з�ʽ
// �̳е��﷨��`class ���� : �̳з�ʽ  ����`
// **�̳з�ʽһ�������֣�**
// * �����̳�
// * �����̳�
// * ˽�м̳�
class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

//�����̳�
class Son1 : public Base1
{
public:
    void func()
    {
        m_A; //�ɷ��� publicȨ��
        m_B; //�ɷ��� protectedȨ��
        //m_C; //���ɷ���
    }
};

void myClass()
{
    Son1 s1;
    s1.m_A; //������ֻ�ܷ��ʵ�����Ȩ��
}

//�����̳�
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
        m_A; //�ɷ��� protectedȨ��
        m_B; //�ɷ��� protectedȨ��
        //m_C; //���ɷ���
    }
};

void myClass2()
{
    Son2 s;
    //s.m_A; //���ɷ���
}

//˽�м̳�
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
        m_A; //�ɷ��� privateȨ��
        m_B; //�ɷ��� privateȨ��
        //m_C; //���ɷ���
    }
};

class GrandSon3 : public Son3
{
public:
    void func()
    {
        //Son3��˽�м̳У����Լ̳�Son3��������GrandSon3�ж��޷����ʵ�
        //m_A;
        //m_B;
        //m_C;
    }
};


// #### 4.6.3 �̳��еĶ���ģ��
// **���⣺**�Ӹ���̳й����ĳ�Ա����Щ�������������
class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C; //˽�г�Աֻ�Ǳ������ˣ����ǻ��ǻ�̳���ȥ
};

//�����̳�
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

//���ۣ� ������˽�г�ԱҲ�Ǳ�����̳���ȥ�ˣ�ֻ���ɱ����������غ���ʲ���


// #### 4.6.4 �̳��й��������˳��
// ����̳и���󣬵������������Ҳ����ø���Ĺ��캯��
// ���⣺���������Ĺ��������˳����˭��˭��
class Base
{
public:
    Base()
    {
        cout << "Base���캯��!" << endl;
    }

    ~Base()
    {
        cout << "Base��������!" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son���캯��!" << endl;
    }

    ~Son()
    {
        cout << "Son��������!" << endl;
    }
};

void test01()
{
    //�̳��� �ȵ��ø��๹�캯�����ٵ������๹�캯��������˳���빹���෴
    Son s;
}

int main()
{
    test01();
    system("pause");
    return 0;
}

//�ܽ᣺�̳��� �ȵ��ø��๹�캯�����ٵ������๹�캯��������˳���빹���෴


// #### 4.6.5 �̳�ͬ����Ա����ʽ
// ���⣺�������븸�����ͬ���ĳ�Ա�����ͨ��������󣬷��ʵ����������ͬ���������أ�
// * ��������ͬ����Ա   ֱ�ӷ��ʼ���
// * ���ʸ���ͬ����Ա   ��Ҫ��������
class Base
{
public:
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base - func()����" << endl;
    }

    void func(int a)
    {
        cout << "Base - func(int a)����" << endl;
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

    //�������븸��ӵ��ͬ���ĳ�Ա��������������ظ��������а汾��ͬ����Ա����
    //�������ʸ����б����ص�ͬ����Ա��������Ҫ�Ӹ����������
    void func()
    {
        cout << "Son - func()����" << endl;
    }

public:
    int m_A;
};

void test01()
{
    Son s;
    cout << "Son�µ�m_A = " << s.m_A << endl;
    cout << "Base�µ�m_A = " << s.Base::m_A << endl;
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

// �ܽ᣺
// 1. ����������ֱ�ӷ��ʵ�������ͬ����Ա
// 2. ����������������Է��ʵ�����ͬ����Ա
// 3. �������븸��ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա����������������Է��ʵ�������ͬ������


// #### 4.6.6 �̳�ͬ����̬��Ա����ʽ
// ���⣺�̳���ͬ���ľ�̬��Ա�������������ν��з��ʣ�
// ��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ��
// - ��������ͬ����Ա   ֱ�ӷ��ʼ���
// - ���ʸ���ͬ����Ա   ��Ҫ��������
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
//ͬ����Ա����
void test01()
{
    //ͨ���������
    cout << "ͨ��������ʣ� " << endl;
    Son s;
    cout << "Son  �� m_A = " << s.m_A << endl;
    cout << "Base �� m_A = " << s.Base::m_A << endl;
    //ͨ����������
    cout << "ͨ���������ʣ� " << endl;
    cout << "Son  �� m_A = " << Son::m_A << endl;
    cout << "Base �� m_A = " << Son::Base::m_A << endl;
}

//ͬ����Ա����
void test02()
{
    //ͨ���������
    cout << "ͨ��������ʣ� " << endl;
    Son s;
    s.func();
    s.Base::func();
    cout << "ͨ���������ʣ� " << endl;
    Son::func();
    Son::Base::func();
    //����ͬ������������ص�����������ͬ����Ա��������Ҫ�������������
    Son::Base::func(100);
}

int main()
{
    //test01();
    test02();
    system("pause");
    return 0;
}

//�ܽ᣺ͬ����̬��Ա����ʽ�ͷǾ�̬����ʽһ����ֻ���������ַ��ʵķ�ʽ��ͨ������ �� ͨ��������

// #### 4.6.7 ��̳��﷨
// C++����**һ����̳ж����**
// �﷨��` class ���� ���̳з�ʽ ����1 �� �̳з�ʽ ����2...`
// ��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������
// **C++ʵ�ʿ����в������ö�̳�**
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
        m_A = 200; //��ʼ��m_B ��������⣬���Ǹ�ΪmA�ͻ���ֲ���ȷ
    }

public:
    int m_A;
};

//�﷨��class ���ࣺ�̳з�ʽ ����1 ���̳з�ʽ ����2
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

//��̳����ײ�����Աͬ�������
//ͨ��ʹ������������������ֵ�����һ������ĳ�Ա
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


// #### 4.6.8 ���μ̳�
// **���μ̳и��**
//����������̳�ͬһ������
//����ĳ����ͬʱ�̳�������������
//���ּ̳б���Ϊ���μ̳У�������ʯ�̳�

// 1.��̳��˶�������ݣ���ͬ���̳��˶�������ݣ���������ʹ������ʱ���ͻ���������ԡ�
// 2.������̳��Զ�������ݼ̳������ݣ���ʵ����Ӧ������������������ֻ��Ҫһ�ݾͿ���
class Animal
{
public:
    int m_Age;
};

//�̳�ǰ��virtual�ؼ��ֺ󣬱�Ϊ��̳�
//��ʱ�����ĸ���Animal��Ϊ�����
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