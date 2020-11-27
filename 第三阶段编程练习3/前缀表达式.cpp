/*****
描述
    前缀表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的前缀表示法为+ 2 3。前缀表达式的
    优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，例如(2 + 3) * 4的前缀表示法为* + 2 3 4。
    本题求解前缀表达式的值，其中运算符包括+ - * /四个。
关于输入
    输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。
关于输出
    输出为一行，表达式的值。
    可直接用printf("%f\n", v)输出表达式的值v。
例子输入
    * + 11.0 12.0 + 24.0 35.0
例子输出
    1357.000000
提示
    可使用atof(str)把字符串转换为一个double类型的浮点数。atof定义在stdlib.h中。
    此题可使用函数递归调用的方法求解。
*****/

#include <cstdio>
#include <cstdlib>

#define MAX_LEN 100

double func()
{
    char str[MAX_LEN] = "\0";
    double val = 0;
    scanf("%s", str);
    switch (str[0])
    {
    case '+': val = func() + func(); break;
    case '-': val = func() - func(); break;
    case '*': val = func() * func(); break;
    case '/': val = func() / func(); break;
    default: val = atof(str); break;
    }
    return val;
}

int main()
{
    printf("%f\n", func());
    return  0;
}
