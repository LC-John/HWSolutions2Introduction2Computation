/*****
描述
    编程，输入一个字符串，输出该字符串是否回文。
    关于输入
输入为一行字符串（字符串中没有空白字符，字符串长度不超过100）。
关于输出
    如果字符串是回文，输出yes；否则，输出no。
例子输入
    abcdedcba
例子输出
    yes
提示
    回文是指顺读和倒读都一样的字符串。
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
