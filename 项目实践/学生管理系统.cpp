#include<iostream>
#include<string>
#include<vector>
//创建学生的结构体
struct student
{
  std::string name;         //字符类型的名字
    int id;                 //整型的id
    float grade;            //浮点型的分数
};
void  AddStudent(std::string name,int id,float grade)
{
     student NewStudent{name,id,grade};
}
void PrintStudent(student)
{
    std::cout<<"Name: "<<student.name;
}
int main()
{
    int select;
    do
    {
        std::cout << "\n===== 学生信息管理系统 =====" << std::endl;
        std::cout << "1. 添加学生" << std::endl;
        std::cout << "2. 显示所有学生" << std::endl;
        std::cout << "3. 根据ID查找学生" << std::endl;
        std::cout << "4. 退出" << std::endl;
        std::cout<<"请选择编号(1-4)"<<std::endl;
        std::cin>>select;
        if(select == 1)
        {
            //添加学生信息
            std::string name;
            int id;
            float grade;
            std::cout << "学生姓名" << std::endl;
            std::cin>>name;
            std::cout << "学生id" << std::endl;
            std::cin>>id;
            std::cout << "学生分数" << std::endl;
            std::cin>>grade;
            AddStudent(name,id,grade);
        }else if(select == 2)
        {
            student NewStudent;
        }
    }
    while (select!=4);
}
