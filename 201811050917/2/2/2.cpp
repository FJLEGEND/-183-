// 一堆猴子都有编号，编号是1，2，3 ...m，这群猴子（m个）按照1-m的顺序围坐一圈，从第1开始数，每数到第N个，该猴子就要离开此圈，这样依次下来，直到圈中只剩下最后一只猴子，则该猴子为大王。
//基本要求：                                                                          1,m,m-1.....2
//（1） 输入数据：输入m, n m, n 为整数，n < m 
//   （2）中文提示按照m个猴子，数n个数的方法，输出为大王的猴子是几号 ，建立一个函数来实现此功能
//   （3）分别用数组和链表来实现，并比较分析不同存储结构下的时间复杂度和空间复杂度。

//
#include<stdio.h>
#include <iostream>
using namespace std;

struct monkey
{
    int num=1;
    int leave = 0;
    struct monkey* next= NULL;
};

void shuzu(int m, int n)
{
    int N=1,M=m-1;
    monkey monkey1[100];
    for (int i = 0; i < m; i++)
    {
        monkey1[i].num = i + 1;
        monkey1[i].leave = 0;
        
    }
    for (int i = 0;; i++)
    {
        if( N != n)
        {
            N++;
        }
        else
        {
            N = 1;
            monkey1[i].leave = 1;
            M--;
        }
        if (i == m )
        {
            i = 0;
        }
      cout <<monkey1[i].num<< ":"<<monkey1[i].leave<<endl;
        if (M == 0) break;
    }
    for (int i = 0; i < m; i++)
    {
        if (monkey1[i].leave == 0)
        {
            cout << "猴王是:" << monkey1[i].num << endl;
            break;
        }
    }

}

void lianbiao(int m, int n)
{
    int m_num = 0;//要减去的m大小
    int M = m,N = 1;
    monkey *king=NULL;
    monkey* head = NULL;
    monkey* prev = NULL;
    while (M)
    {
       
        king = new monkey;
        if (head == NULL)
        {
            king->num = 1;
            head = king;
        }
        else
        { 
            if (M == 2)
            {
                prev->next = king;
                king->num = M;
                prev = king;
                //king、prev都指向2
                //连到head 
                king->next = head;
                prev =king;
                break;
            }
            else
            {
                prev->next = king;
                king->num = M;
                M--;
            }
           
        }
        //cout << "num:"<<  king->num <<endl;
        //cout << "创建完成" << endl;
        prev = king;
       
    }
    M = m;//剩余猴子
    king = head;
    while (M!=1)
    {
        prev = king;
        if (N == n)
        {
            N = 0;
            prev->leave = 1;
          //  cout <<prev->num<<":"<< prev->leave << endl;
            M--;
        }
        N++;
        king = prev->next;
    }
    king = head;
    while (1)
    {
        prev = king;
        if (prev->leave == 0)
        {
            cout << "猴王是：" << prev->num << endl;
            break;
        }
        else
        {
            king = prev->next;
        }
    }
    prev = head;
    while (m)
    {
        //cout << prev->num << endl;
        king = prev;
        //cout << king->num << endl;
        prev = prev->next;
        delete king;
        //if ( !prev->next) break;
        m--;
    }
 
}

int main()
{
    int m, n;
    cout << "输入猴子数m和周期n(n<m)：" << endl;
    cin >> m >> n;
    //数组
    cout << "数组:" << endl;
    shuzu(m,n);
    //链表
    //cout << "链表:" << endl;
    //lianbiao(m,n);
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
