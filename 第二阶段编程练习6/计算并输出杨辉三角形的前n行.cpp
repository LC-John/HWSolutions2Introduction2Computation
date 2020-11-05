/*****
描述
    写一个程序，它能够计算并输出杨辉三角形前面的n行(n<=30)。
关于输入
    输入只有一行，输入一个正整数n。
关于输出
    输出杨辉三角形的前n行。
    每行输出的第一个数前面没有空格，相邻两个数之间用一个空格隔开。
例子输入
    6
例子输出
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    1 5 10 10 5 1
提示
    杨辉三角形按下图定义：
                      1
                    1   1
                  1   2   1
                1   3   3   1
              1   4   6   4   1
            1   5   10  10  5   1
          ..........................
        ..............................
    每行中的数值由上一行相邻两个数相加得到。
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 100


// 计算的过程中不需要存储整个杨辉三角，只要存储当前正在计算的层的上一层即可
// 使用两层的数组swp来存存储，cur指向的层为上一层的结果，1-cur指向的层为正在计算的一层
// 完成当前层的计算并输出后，赋值cur为1-cur即可完成交换
int swp[2][MAX_N] = {0};
int cur = 0;

int main()
{
    int n = 0;
    cin >> n;
    swp[cur][0] = 1;    // 初始的第0层，恒为1
    cout << 1 << endl;
    for (int i = 1; i < n; i++)
    {
        int nxt = 1 - cur;  // cur为上一层，nxt为正在计算的层
        memset(swp[nxt], 0, sizeof(int) * MAX_N);
        swp[nxt][0] = 1;    // 每一层都以1开始
        cout << 1;
        for (int j = 1; j < i; j++) // 计算nxt层并输出
        {
            swp[nxt][j] = swp[cur][j] + swp[cur][j-1];
            cout << " " << swp[nxt][j];
        }
        swp[nxt][i] = 1;    // 每一层都以1结尾
        cout << " " << 1 << endl;
        cur = nxt;  // 完成计算和输出，交换
    }
    return 0;
}
