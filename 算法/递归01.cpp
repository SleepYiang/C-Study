//递归函数的自我调用
//eg: an=a(n-1)+3
//预知下一项，必须中知道前一项的值

//使用递归求等比数列
//题目：输入一个整数，求出等比数列2，4，8，16，32 ...的第N项的值
//输入一个整数n
//输出:一个整数，等比数列的结果
//输出：6  输出64
#include<iostream>
using namespace std;
int faction(int n)   //定义一个函数实现
{
    int res;  //定义一个输出
    if (n==1) //结束调用条件
    {
        res=2;//首项
    }
    else
    {
        res=faction(n-1)*2;//函数的自调用
    }
    return res;
}
int main0()
{
    cout<<"请输入一个整数n:"<<endl;
    int n;
    cin >>n ;
    cout<<faction(n)<<endl;
    return 0;
}


//使用递归实现函数求阶乘
//（5！=5*4*5*2*1）
//题目:输入一个整数n，求出n的阶乘结果。
//输入一个整数n
//输出:一个整数，n!的结果
//输入：5 输出：120
int faction1(int n)
{
    int resu;
    if (n==1)
    {
        resu=1;
    }
    else
    {
        resu=faction1(n-1)*n;
    }
    return resu;
}
int main()
{
    cout<<faction1(5)<<endl;
    return 0;
}

