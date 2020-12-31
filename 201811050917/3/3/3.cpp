// 3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//某小学最近得到了一笔赞助，打算拿出其中一部分为学习成绩优秀的前5名学生发奖学金。期末，每个学生都有3门课的成绩:语文、数学、英语。
//先按总分从高到低排序，如果两个同学总分相同，再按语文成绩从高到低排序，如果两个同学总分和语文成绩都相同，那么规定学号小的同学 排在前面，这样，每个学生的排序是唯一确定的。
//任务：先根据输入的3门课的成绩计算总分，然后按上述规则排序，最后按排名顺序输出前五名名学生的学号和总分。注意，在前5名同学中，每个人的奖学金都不相同，因此，你必须严格按上述规则排序。
#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
struct grade
{
    int num;
    int chinese;
    int math;
    int english;
    int total_points;
};
void fun(grade x[],int n)
{
    int i, j;
    grade temp;
    //先按总分从高到低
    for (i = 0; i < n-1 ; i++)
    {
        for (j = 0; j < n-1 - i; j++)
        {
            if (x[j].total_points < x[j + 1].total_points)
            {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
            else if (x[j].total_points == x[j + 1].total_points)
            {
                if (x[j].chinese < x[j + 1].chinese)
                {
                    temp = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = temp;
                }
                else if (x[j].chinese == x[j + 1].chinese)
                {
                    if (x[j].num > x[j + 1].num)
                    {
                        temp = x[j];
                        x[j] = x[j + 1];
                        x[j + 1] = temp;
                    }
                }
            }
        }
    }
    //如果两个同学总分相同，再按语文成绩从高到低排序
   //如果两个同学总分和语文成绩都相同，那么规定学号小的同学 排在前面
}
int main()
{
    int n;
    int point[100];
    grade student[10];
    cout << "输入参加评选的学生人数(小于10)：";
    cin >> n;
    cout << endl;
    //输入学生信息
    ifstream  afile;
    afile.open("data.txt",ios::in);
    if (!afile)
    {
        cout << "文件不能打开" << endl;
    }
    else
    {
        for (int p = 0; p < 100; p++)
        {
            afile >> point[p];
        }
    }
    for (int j = 0; j < n; j++)
    {
        static int j2 = 0;
        student[j].num = j+1;
        student[j].chinese = point[j2];
        student[j].math =point[j2+1] ;
        student[j].english = point[j2+2];
        student[j].total_points = student[j].chinese + student[j].math + student[j].english;
        j2 += 3;
    }
    afile.close();
    //列总成绩表
    cout << "列出总成绩表（按学号顺序）：" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << student[i].chinese << " " << student[i].math << " " << student[i].english << endl;
    }
    //排序
    fun(student, n);
    cout << "排名为：" << endl;
    for (int i = 0; i <5; i++)
    {
        
        cout << student[i].num << " " << student[i].total_points << endl;
    }
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
