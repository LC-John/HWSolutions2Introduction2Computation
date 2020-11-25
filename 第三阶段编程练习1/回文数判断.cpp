/*****
描述
    给定一个正整数（不超过9位），判断其是否为回文数。所谓回文数是指正向看与逆向看相等的数。
    如，123454321，12344321。若是，输出yes,若不是，输出no
关于输入
    一个正整数
关于输出
    若是，输出yes
    若不是，输出no
例子输入
    135797531
例子输出
    yes
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000

bool check(char* str)
{
    char rev_str[MAX_N] = "\0";
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
        rev_str[len - 1 - i] = str[i];
    for (int i = 0; i < len; i++)
        if (str[i] != rev_str[i])
            return false;
    return true;
    // 直接使用strcmp函数比较两个字符串
    //return strcmp(str, rev_str) == 0;
}


int main()
{
    char str[MAX_N] = "\0";
    cin >> str;
    if (check(str))
        cout << "yes";
    else
        cout << "no";
    return 0;
}
