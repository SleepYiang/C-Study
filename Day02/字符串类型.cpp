// ### 2.6 字符串型
//
// **作用**：用于表示一串字符
//
// **两种风格**
//
// 1. **C风格字符串**： `char 变量名[] = "字符串值"`
//
//    示例：
#include<iostream>
#include<string>
using namespace std;
   int main() {
    char str1[] = "hello world";
    cout << str1 << endl;
    system("pause");
    return 0;
}
//
// > 注意：C风格的字符串要用双引号括起来
//
// 1. **C++风格字符串**：  `string  变量名 = "字符串值"`
//
// 示例：
using namespace std;
int main() {
    string str = "hello world";
    cout << str << endl;
    system("pause");
    return 0;
}
// > 注意：C++风格字符串，需要加入头文件==#include\<string>==
