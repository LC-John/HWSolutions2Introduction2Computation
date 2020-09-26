/*****
描述
    输入三个整数,输出最大的数。
关于输入
    输入为一行，共三个整数。
关于输出
    输出为最大的整数。
例子输入
    10 20 56
例子输出
    56
*****/

#include <iostream>
//#include <cmath>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    // 以下注释为偷懒做法，请同学们自行百度理解
    //cout << max(a, max(b, c));
    if (a < b)
        a = b;
    if (a < c)
        a = c;
    cout << a;
    return 0;
}
