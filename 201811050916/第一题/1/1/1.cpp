﻿// 1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//编写一个能将两个数合并成一个数的函数fun，具体合并方式是：将两个两位数的正整数a和b合并形成一个整数放在c中，并将a的十位和个位依次存放在c数的十位和千位上，b的十位和个位依次存放在c数的个位和百位上，基本要求：在主函数中调用fun函数，fun函数要写出以下三种：（1）通过返回值将新数c传给主函数；（2）通过引用参数将新数传给主函数；（3）通过指针型参数将新数传给主函数。

#include <iostream>
#include <stdio.h>
using namespace std;
int fun1(int x, int y)
{
int c=0;
int a1,a10;
int b1,b10;

a1=x/10;
a10=x%10;
b1=y/10;
b10=y%10;
c=a1*1000+b1*100+a10*10+b10*1;
return c;
}
void fun2(int &x, int &y,int &c)
{
    int a1, a10;
    int b1, b10;
    a1 = x / 10;
    a10 = x % 10;
    b1 = y / 10;
    b10 = y % 10;
    c = a1 * 1000 + b1 * 100 + a10 * 10 + b10 * 1;
}
void fun3(int *x, int *y,int *c)
{
   int a1 = *x / 10;
    int a10 = *x % 10;
    int b1 = *y / 10;
    int b10 = *y % 10;
    *c = a1 * 1000 + b1 * 100 + a10 * 10 + b10 * 1;
}
int main()
{
    int a, b;
    int c=0;
    cout << "输入两个两位数。：";
    cin >> a >> b;
    cout << endl;
    c = fun1(a, b);
    cout << "(1):" << c  << endl;
    fun2(a,b,c);
    cout << "(2):" << c << endl;
    fun3(&a,&b,&c);
    cout << "(3):" << c << endl;
    system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
