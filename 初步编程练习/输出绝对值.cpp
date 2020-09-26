/*****
描述
    输入一个浮点数，输出这个浮点数的绝对值。
关于输入
    一行，一个浮点数
关于输出
    输出这个浮点数的绝对值，保留两位小数
例子输入
    1.23
    -3.14
例子输出
    1.23
    3.14
提示
    要让输出保持两位小数，可以
    并在#include部分增加：对 iomanip 的引用
    使用如下的语句进行输出：
    cout << setiosflags(ios::fixed) << setprecision(2) << x << endl;
*****/

#include <iostream>
#include <iomanip>
//#include <cstdio>
//#include <cmath>
using namespace std;

int main()
{
    float a;
    cin >> a;
    if (a < 0)
        a = -a;
    cout << setiosflags(ios::fixed) << setprecision(2) << a;
    // 使用printf和fabs的方法，请自行百度理解
    //printf("%.2f", fabs(a));
    return 0;
}
