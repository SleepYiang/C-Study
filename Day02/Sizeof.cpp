// 2.2 sizeof�ؼ���
//
// ���ã�����sizeof�ؼ��ֿ���==ͳ������������ռ�ڴ��С==
//
// �﷨: `sizeof( �������� / ����)`
//
// ʾ����
//
#include<iostream>
using namespace std;
int main() {

    cout << "short ������ռ�ڴ�ռ�Ϊ�� " << sizeof(short) << endl;

    cout << "int ������ռ�ڴ�ռ�Ϊ�� " << sizeof(int) << endl;

    cout << "long ������ռ�ڴ�ռ�Ϊ�� " << sizeof(long) << endl;

    cout << "long long ������ռ�ڴ�ռ�Ϊ�� " << sizeof(long long) << endl;

    system("pause");

    return 0;
}
// > **���ͽ���**��==short < int <= long <= long long==
