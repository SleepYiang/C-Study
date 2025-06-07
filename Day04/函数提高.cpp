// ## 3 �������
// ### 3.1 ����Ĭ�ϲ���
// ��C++�У��������β��б��е��β��ǿ�����Ĭ��ֵ�ġ�
// �﷨��`����ֵ����  ������ ������= Ĭ��ֵ��{}`
#include<iostream>
using namespace std;
int func(int a, int b = 10, int c = 10) {
    return a + b + c;
}
//1. ���ĳ��λ�ò�����Ĭ��ֵ����ô�����λ�����󣬴������ң����붼Ҫ��Ĭ��ֵ
//2. �������������Ĭ��ֵ������ʵ�ֵ�ʱ��Ͳ�����Ĭ�ϲ���
//�������˾��ô������û����Ĭ��
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
    return a + b;
}
int main() {
    cout << "ret = " << func(20, 20) << endl;
    cout << "ret = " << func(100) << endl;
    system("pause");
    return 0;
}

// ### 3.2 ����ռλ����
// C++�к������β��б��������ռλ������������ռλ�����ú���ʱ�������λ��
// **�﷨��** `����ֵ���� ������ (��������){}`
// ���ֽ׶κ�����ռλ�����������岻�󣬵��Ǻ���Ŀγ��л��õ��ü���
//����ռλ���� ��ռλ����Ҳ������Ĭ�ϲ���
void func(int a, int) {
    cout << "this is func" << endl;
}
int main1()
{
    func(10,10); //ռλ���������
    system("pause");
    return 0;
}
// ### 3.3 ��������
// #### 3.3.1 �������ظ���
// **���ã�**������������ͬ����߸�����
// **������������������**
// * ͬһ����������
// * ����������ͬ
// * ��������**���Ͳ�ͬ**  ���� **������ͬ** ���� **˳��ͬ**
// **ע��:**  �����ķ���ֵ��������Ϊ�������ص�����
//����������Ҫ��������ͬһ����������
void func()
{
    cout << "func �ĵ��ã�" << endl;
}
void func(int a)
{
    cout << "func (int a) �ĵ��ã�" << endl;
}
void func(double a)
{
    cout << "func (double a)�ĵ��ã�" << endl;
}
void func(int a ,double b)
{
    cout << "func (int a ,double b) �ĵ��ã�" << endl;
}
void func(double a ,int b)
{
    cout << "func (double a ,int b)�ĵ��ã�" << endl;
}
//��������ֵ��������Ϊ������������
//int func(double a, int b)
//{
//	cout << "func (double a ,int b)�ĵ��ã�" << endl;
//}
int main3() {
    func();
    func(10);
    func(3.14);
    func(10,3.14);
    func(3.14 , 10);
    system("pause");
    return 0;
}




// #### 3.3.2 ��������ע������
// * ������Ϊ��������
// * ����������������Ĭ�ϲ���
//��������ע������
//1��������Ϊ��������

void func(int &a)
{
    cout << "func (int &a) ���� " << endl;
}
void func(const int &a)
{
    cout << "func (const int &a) ���� " << endl;
}
//2������������������Ĭ�ϲ���
void func2(int a, int b = 10)
{
    cout << "func2(int a, int b = 10) ����" << endl;
}
void func2(int a)
{
    cout << "func2(int a) ����" << endl;
}
int main4() {
    int a = 10;
    func(a); //������const
    func(10);//������const
    //func2(10); //����Ĭ�ϲ����������壬��Ҫ����
    system("pause");
    return 0;
}