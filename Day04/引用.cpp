// ### 2.1 ���õĻ���ʹ��
// **���ã� **�����������
// **�﷨��** `�������� &���� = ԭ��`
#include<iostream>
using namespace std;
int main0() {
    int a = 10;
    int &b = a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    system("pause");
    return 0;
}
// ### 2.2 ����ע������
// * ���ñ����ʼ��
// * �����ڳ�ʼ���󣬲����Ըı�
#include<iostream>
using namespace std;
int main1() {
    int a = 10;
    int b = 20;
    //int &c; //�������ñ����ʼ��
    int &c = a; //һ����ʼ���󣬾Ͳ����Ը���
    c = b; //���Ǹ�ֵ���������Ǹ�������
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    system("pause");
    return 0;
}
// ### 2.3 ��������������
// **���ã�**��������ʱ�������������õļ������β�����ʵ��
// **�ŵ㣺**���Լ�ָ���޸�ʵ��
//1. ֵ����
void mySwap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;  //�βθı�ʵ��û�з����ı�
}
//2. ��ַ����
void mySwap02(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//3. ���ô���
void mySwap03(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int main2() {
    int a = 10;
    int b = 20;
    mySwap01(a, b);
    cout << "a:" << a << " b:" << b << endl;
    mySwap02(&a, &b);
    cout << "a:" << a << " b:" << b << endl;
    mySwap03(a, b);
    cout << "a:" << a << " b:" << b << endl;
    system("pause");
    return 0;
}
// �ܽ᣺ͨ�����ò���������Ч��ͬ����ַ������һ���ġ����õ��﷨�������


// ### 2.4 ��������������ֵ
// ���ã������ǿ�����Ϊ�����ķ���ֵ���ڵ�
// ע�⣺**��Ҫ���ؾֲ���������**
// �÷�������������Ϊ��ֵ

//���ؾֲ���������
int& test01() {
    int a = 10; //�ֲ�����
    return a;
}
//���ؾ�̬��������
int& test02() {
    static int a = 20;
    return a;
}
int main3() {
    //���ܷ��ؾֲ�����������
    int& ref = test01();
    cout << "ref = " << ref << endl;
    cout << "ref = " << ref << endl;
    //�����������ֵ����ô���뷵������
    int& ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;
    test02() = 1000;
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;
    system("pause");
    return 0;
}

// ### 2.5 ���õı���
// ���ʣ�**���õı�����c++�ڲ�ʵ����һ��ָ�볣��
//���������ã�ת��Ϊ int* const ref = &a;
void func(int& ref){
    ref = 100; // ref�����ã�ת��Ϊ*ref = 100
}
int main(){
    int a = 10;
    //�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
    int& ref = a;
    ref = 20; //�ڲ�����ref�����ã��Զ�������ת��Ϊ: *ref = 20;
    cout << "a:" << a << endl;
    cout << "ref:" << ref << endl;
    func(a);
    cout << "a:" << ref << endl;
    return 0;
}

// ### 2.6 ��������
// **���ã�**����������Ҫ���������βΣ���ֹ�����
// �ں����β��б��У����Լ�==const�����β�==����ֹ�βθı�ʵ
//����ʹ�õĳ�����ͨ�����������β�
void showValue(const int& v) {
    //v += 10;
    cout << v << endl;
}

int main5() {
    //int& ref = 10;  ���ñ�����Ҫһ���Ϸ����ڴ�ռ䣬������д���
    //����const�Ϳ����ˣ��������Ż����룬int temp = 10; const int& ref = temp;
    const int& ref = 10;
    //ref = 100;  //����const�󲻿����޸ı���
    cout << ref << endl;
    //���������ó������÷�ֹ������޸�ʵ��
    int a = 10;
    showValue(a);
    system("pause");
    return 0;
}