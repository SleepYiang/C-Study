// **����������**
// ѧУ������������Ŀ��ÿ����ʦ����5��ѧ�����ܹ���3����ʦ����������
// ���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա
// ѧ���ĳ�Ա�����������Է���������������3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ
// ���մ�ӡ����ʦ�����Լ���ʦ������ѧ�����ݡ�
#include<iostream>
using namespace std;
#include<string>
//����ѧ���Ľṹ��
struct student
{
    string name;
    int score;
};
//������ʦ�Ľṹ��
struct teacher
{
    string name;
    student sArray[5];
};
void CreatSpace(teacher tArray[],int length)
{
    string tName = "��ʦ";
    string sName = "ѧ��";
    string nameSeed = "ABCDE";;
    for(int i=0;i<length;i++)
    {
        tArray[i].name=tName+nameSeed[i];
        for(int j=0;j<5;j++)
        {
            tArray[i].sArray[j].name=sName+nameSeed[j];
            tArray[i].sArray[j].score=60;
        }
    }
}
void print(teacher tArray[],int length)
{
    string nameSeed="ABCDE";
    for(int i=0;i<length;i++)
    {
        cout<<tArray[i].name<<endl;
        for (int j=0;j<5;j++)
        {
            cout<<"\t����"<<tArray[i].sArray[j].name<<"����"<<tArray[i].sArray[j].score<<endl;
        }
    }

}
int main()
{
    teacher tArray[3];
    int length= sizeof(tArray)/sizeof(teacher);
    CreatSpace(tArray,length);
    print(tArray,length);
    system("pause");
}