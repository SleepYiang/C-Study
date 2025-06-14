// **作用**：用于处理四则运算
//
// 算术运算符包括以下符号：
//
// | **运算符** | **术语**   | **示例**    | **结果**  |
// | ---------- | ---------- | ----------- | --------- |
// | +          | 正号       | +3          | 3         |
// | -          | 负号       | -3          | -3        |
// | +          | 加         | 10 + 5      | 15        |
// | -          | 减         | 10 - 5      | 5         |
// | *          | 乘         | 10 * 5      | 50        |
// | /          | 除         | 10 / 5      | 2         |
// | %          | 取模(取余) | 10 % 3      | 1         |
// | ++         | 前置递增   | a=2; b=++a; | a=3; b=3; |
// | ++         | 后置递增   | a=2; b=a++; | a=3; b=2; |
// | --         | 前置递减   | a=2; b=--a; | a=1; b=1; |
// | --         | 后置递减   | a=2; b=a--; | a=1; b=2; |
//
#include<iostream>
using namespace std;
int main()
{
    int a1 = 10;
    int b1 = 3;
    cout << a1 + b1 << endl;
    cout << a1 - b1 << endl;
    cout << a1 * b1 << endl;
    cout << a1 / b1 << endl;  //两个整数相除结果依然是整数
    int a2 = 10;
    int b2 = 20;
    cout << a2 / b2 << endl;
    int a3 = 10;
    int b3 = 0;
    //cout << a3 / b3 << endl; //报错，除数不可以为0
    //两个小数可以相除
    double d1 = 0.5;
    double d2 = 0.25;
    cout << d1 / d2 << endl;
    system("pause");
    return 0;
}
