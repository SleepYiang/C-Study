// **����������**
//���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա�;�����ṹ�����飬�����д��5��Ӣ�ۡ�
//ͨ��ð��������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ����
//����Ӣ����Ϣ���£�
// {"����",23,"��"},
// {"����",22,"��"},
// {"�ŷ�",20,"��"},
// {"����",21,"��"},
// {"����",19,"Ů"},
#include<iostream>
#include<string>
using namespace std;
struct hero
{
    string name;
    int age;
    string gender;
};
void BobbleSort(hero arr[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1-i;j++)
        {
            if(arr[j].age > arr[j+1].age)
            {
                hero temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void print(hero arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<"����:"<<arr[i].name<<"����:"<<arr[i].age<<"�Ա�:"<<arr[i].gender<<endl;
    }
}

int main()
{
    struct hero arr[5]=
    {
    {"����",22,"��"},
    {"�ŷ�",20,"��"},
    {"����",21,"��"},
    {"����",19,"Ů"},
    {"����",23,"��"},
    };
    int len=sizeof(arr)/sizeof(hero);
    BobbleSort(arr,len);
    print(arr,len);
}
