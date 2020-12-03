/*****
描述
    判断某年是否是闰年。
关于输入
    输入只有一行，包含一个整数a(0 < a < 3000)
关于输出
    一行，如果公元a年是闰年输出Y，否则输出N
例子输入
    2006
例子输出
    N
*****/

#include <iostream>
using namespace std;

int main()
{
    int y = 0;
    cin >> y;
    if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0)
        cout << "Y";
    else
        cout << "N";
    return 0;
}
