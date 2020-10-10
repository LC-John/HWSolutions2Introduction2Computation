/*****
描述
    给出n的值, 计算公式 e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + … + 1/n!
关于输入
    只有一个输入，即n的值, n>=1, 且n为整数
关于输出
    按照上述公式求出的e的值（精确到小数点后6位）
例子输入
    5
例子输出
    2.716667
*****/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double e = 1, n = 1;
    cin >> n;
    for (int factorial = 1, base = 1; base <= n; base++)
    {
        factorial *= base;
        e += 1. / factorial;
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << e;
    return 0;
}
