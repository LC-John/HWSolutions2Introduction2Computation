/*****
描述
    输入一个句子（一行），将句子中的每一个单词翻转后输出
关于输入
    只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。
关于输出
    翻转每一个单词后的字符串
例子输入
    hello world
例子输出
    olleh dlrow
提示
    1. 每个句子都只有一行，是一个只包含空格和字母的字符串。
    2. 单词与单词间的空格可能不只一个。
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 200

char str[MAX_N] = "\0";
int len = 0;

int main()
{
    int idx = 0;
    cin.getline(str, MAX_N);
    len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] == ' ')
            str[i] = '\0';
    for (int i = 0; i < len; i++)
    {
        if (str[i] != '\0')
        {
            reverse(str + i, str + i + strlen(str + i));    // 翻转单词
            i += strlen(str + i);
        }
    }
    for (int i = 0; i < len; i++)
        if (str[i] == '\0')
            cout << " ";
        else
            cout << str[i];
    return 0;
}
