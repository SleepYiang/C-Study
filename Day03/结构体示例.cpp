// **案例描述：**
// 学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
// 设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
// 学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
// 最终打印出老师数据以及老师所带的学生数据。
#include<iostream>
using namespace std;
#include<string>
//创建学生的结构体
struct student
{
    string name;
    int score;
};
//创建老师的结构体
struct teacher
{
    string name;
    student sArray[5];
};
void CreatSpace(teacher tArray[],int length)
{
    string tName = "教师";
    string sName = "学生";
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
            cout<<"\t姓名"<<tArray[i].sArray[j].name<<"分数"<<tArray[i].sArray[j].score<<endl;
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