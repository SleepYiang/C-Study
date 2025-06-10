#include<iostream>
#include<string>
using namespace std;
#define max 2000
void ShowMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}
int main()
{
    while(true)
    {
        int choice=0;
        ShowMenu();
        cout << "请输相关数字: " << endl;
        cin>>choice;
        switch(choice)
        {
        case 1://添加联系人
            break;
        case 2://显示联系人
            break;
        case 3://删除联系人
            break;
        case 4://查找联系人
            break;
        case 5://修改联系人
            break;
        case 6://清空联系人
            break;
        case 0://退出通讯录
           cout<<"欢迎下次使用"<<endl;
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
