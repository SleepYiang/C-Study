// ### 7.1 指针的基本概念
// **指针的作用：** 可以通过指针间接访问内存
// * 内存编号是从0开始记录的，一般用十六进制数字表示
// * 可以利用指针变量保存地址

// ### 7.2 指针变量的定义和使用
// 指针变量定义语法： `数据类型 * 变量名
#include<iostream>
using namespace std;
int main() {
    //1、指针的定义
    int a = 10; //定义整型变量a
    //指针定义语法： 数据类型 * 变量名 ;
    int * p;
    //指针变量赋值
    p = &a; //指针指向变量a的地址
    cout << &a << endl; //打印数据a的地址
    cout << p << endl;  //打印指针变量p
    //2、指针的使用
    //通过*操作指针变量指向的内存
    cout << "*p = " << *p << endl;
    system("pause");
    return 0;
}
// 指针变量和普通变量的区别
// * 普通变量存放的是数据,指针变量存放的是地址
// * 指针变量可以通过" * "操作符，操作指针变量指向的内存空间，这个过程称为解引用
// > 总结1： 我们可以通过 & 符号 获取变量的地址
// > 总结2：利用指针可以记录地址
// > 总结3：对指针变量解引用，可以操作指针指向的内存

// ### 7.3 指针所占内存空间
// 提问：指针也是种数据类型，那么这种数据类型占用多少内存空间？
int main1() {
    int a = 10;
    int * p;
    p = &a; //指针指向数据a的地址
    cout << *p << endl; //* 解引用
    cout << sizeof(p) << endl;
    cout << sizeof(char *) << endl;
    cout << sizeof(float *) << endl;
    cout << sizeof(double *) << endl;
    system("pause");
    return 0;
}
// 总结：所有指针类型在32位操作系统下是4个字节

// ### 7.4 空指针和野指针
// **空指针**：指针变量指向内存中编号为0的空间
// **用途：**初始化指针变量
// **注意：**空指针指向的内存是不可以访问的
//空指针
int main2() {
    //指针变量p指向内存地址编号为0的空间
    int * p = NULL;
    //访问空指针报错
    //内存编号0 ~255为系统占用内存，不允许用户访问
    cout << *p << endl;
    system("pause");
    return 0;
}
//**野指针**：指针变量指向非法的内存空间
int main3() {
    //指针变量p指向内存地址编号为0x1100的空间
    int * p = (int *)0x1100;
    //访问野指针报错
    cout << *p << endl;
    system("pause");
    return 0;
}
//总结：空指针和野指针都不是我们申请的空间，因此不要访问。

// ### 7.5 const修饰指针
// const修饰指针有三种情况
// 1. const修饰指针   --- 常量指针
// 2. const修饰常量   --- 指针常量
// 3. const即修饰指针，又修饰常量
int main4() {
    int a = 10;
    int b = 10;
    //const修饰的是指针，指针指向可以改，指针指向的值不可以更改
    const int * p1 = &a;
    p1 = &b; //正确
    //*p1 = 100;  报错
    //const修饰的是常量，指针指向不可以改，指针指向的值可以更改
    int * const p2 = &a;
    //p2 = &b; //错误
    *p2 = 100; //正确
    //const既修饰指针又修饰常量
    const int * const p3 = &a;
    //p3 = &b; //错误
    //*p3 = 100; //错误
    system("pause");
    return 0;
}
//技巧：看const右侧紧跟着的是指针还是常量, 是指针就是常量指针，是常量就是指针常量

// ### 7.6 指针和数组
// **作用：**利用指针访问数组中元素
int main5() {
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int * p = arr;  //指向数组的指针
    cout << "第一个元素： " << arr[0] << endl;
    cout << "指针访问第一个元素： " << *p << endl;
    for (int i = 0; i < 10; i++)
    {
        //利用指针遍历数组
        cout << *p << endl;
        p++;
    }
    system("pause");
    return 0;
}

// ### 7.7 指针和函数
// **作用：**利用指针作函数参数，可以修改实参的值
//值传递
void swap1(int a ,int b)
{
    int temp = a;
    a = b;
    b = temp;
}
//地址传递
void swap2(int * p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main6() {
    int a = 10;
    int b = 20;
    swap1(a, b); // 值传递不会改变实参
    swap2(&a, &b); //地址传递会改变实参
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    system("pause");
    return 0;
}
//总结：如果不想修改实参，就用值传递，如果想修改实参，就用地址传递

// ### 7.8 指针、数组、函数
// **案例描述：**封装一个函数，利用冒泡排序，实现对整型数组的升序排序
// 例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
//冒泡排序函数
void bubbleSort(int * arr, int len)  //int * arr 也可以写为int arr[]
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
//打印数组函数
void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}
int main7() {
    int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
    int len = sizeof(arr) / sizeof(int);
    bubbleSort(arr, len);
    printArray(arr, len);
    system("pause");
    return 0;
}
//总结：当数组名传入到函数作为参数时，被退化为指向首元素的指针