/*****
描述
    给定三个整数，求这三个数中最大值与最小值之差。
关于输入
    只有一行，包括待处理的三个整数。
关于输出
    一共一行，输出最大数减去最小数的差。
例子输入
    3 5 9
例子输出
    6
提示
    三个数中可能出现相等的情况
*****/

#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c;
    if (a < b)
    {
        d = a;
        a = b;
        b = d;
    }
    if (a < c)
    {
        d = a;
        a = c;
        c = d;
    }
    if (b < c)
    {
        d = b;
        b = c;
        c = d;
    }
    cout << a - c;
    return 0;
}
