/*****
描述
    一个最简单的计算器，支持+, -, *, / 四种运算。仅需考虑输入输出为整数的情况，数据和运算结果不会超过int表示的范围。
关于输入
    输入只有一行，共有三个参数，其中第1、2个参数为整数，第3个参数为操作符（+,-,*,/）。
关于输出
    输出只有一行，一个整数，为运算结果。然而：
    1. 如果出现除数为0的情况，则输出：Divided by zero!
    2. 如果出现无效的操作符(即不为 +, -, *, / 之一），则输出：Invalid operator!
例子输入
    1 2 +
例子输出
    3
提示
    可以考虑使用if和switch结构。
*****/

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char c;
    cin >> a >> b >> c;
    if ('+' == c)
        cout << a + b;
    else if ('-' == c)
        cout << a - b;
    else if ('*' == c)
        cout << a * b;
    else if ('/' == c)
    {
        if (0 == b)
            cout << "Divided by zero!";
        else
            cout << a / b;
    }
    else
        cout << "Invalid operator!";
    // 以下为switch写法
    /*
    switch(c)
    {
    case '+':
        cout << a + b; break;
    case '-':
        cout << a - b; break;
    case '*':
        cout << a * b; break;
    case '/':
        if (0 == b)
            cout << "Divided by zero!";
        else
            cout << a / b;
        break;
    default:
        cout << "Invalid operator!";
    }
    */
    return 0;
}
