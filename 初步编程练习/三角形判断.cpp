/*****
描述
    输入三个正整数表示三条边的长度，判断这三条边能否构成一个三角形，如果能，则输出“yes”，否则输出“no”。
关于输入
    输入是三个正整型数，分别表示三条边的长度。
关于输出
    yes 或者 no
例子输入
    3 4 5
例子输出
    yes
*****/

#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a)
        cout << "yes";
    else
        cout << "no";
    return 0;
}
