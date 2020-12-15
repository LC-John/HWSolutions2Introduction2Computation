/*****
描述
    输入三个数（包括整数与浮点数），按由小到大的顺序输出。若输入为整数，则按整数输出；
    若输出为浮点数，则输出为浮点数，且保留小数点后2位。（请使用参数为指针的函数来完成！！！）
关于输入
    输入为三个数，逗号隔开。
关于输出
    输出为按由小到大顺序排列的数，用逗号隔开。
例子输入
    25，48，37
例子输出
    25，37，48
提示
    无。
*****/

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define MAX_N 3

bool cmp(double *a, double *b)
{
    return *a < *b;
}

int main()
{
    double *num[MAX_N] = {NULL};
    for (int i = 0; i < MAX_N; i++)
    {
        if (i > 0)
        {
            char c;
            cin >> c;
        }
        num[i] = new double;
        cin >> *(num[i]);
    }
    sort(num, num + MAX_N, cmp);
    for (int i = 0; i < MAX_N; i++)
    {
        if (i > 0)
            cout << ",";
        if (*(num[i]) - int(*(num[i])) > 0)
            cout << fixed << setprecision(2) << *(num[i]);
        else
            cout << int(*(num[i]));
    }
    return 0;
}
