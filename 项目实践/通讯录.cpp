#include<iostream>
#include<string>
using namespace std;
#define max 2000
void ShowMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1�������ϵ��  *****" << endl;
    cout << "*****  2����ʾ��ϵ��  *****" << endl;
    cout << "*****  3��ɾ����ϵ��  *****" << endl;
    cout << "*****  4��������ϵ��  *****" << endl;
    cout << "*****  5���޸���ϵ��  *****" << endl;
    cout << "*****  6�������ϵ��  *****" << endl;
    cout << "*****  0���˳�ͨѶ¼  *****" << endl;
    cout << "***************************" << endl;
}
int main()
{
    while(true)
    {
        int choice=0;
        ShowMenu();
        cout << "�����������: " << endl;
        cin>>choice;
        switch(choice)
        {
        case 1://�����ϵ��
            break;
        case 2://��ʾ��ϵ��
            break;
        case 3://ɾ����ϵ��
            break;
        case 4://������ϵ��
            break;
        case 5://�޸���ϵ��
            break;
        case 6://�����ϵ��
            break;
        case 0://�˳�ͨѶ¼
           cout<<"��ӭ�´�ʹ��"<<endl;
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
