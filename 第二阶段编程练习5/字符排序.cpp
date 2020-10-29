/*****
描述
    编写程序，对给定的字符串按如下的条件进行排序，并输出排序后的结果。
    条件：从字符串中间一分为二，左边部分按字符的ASCII值降序排序，右边部分保持不变,然后将左边部分与右边
    部分进行交换。如果原字符串长度为奇数，则最中间的字符不参加处理，字符仍放在原位置上。
关于输入
    输入为一个字符串
关于输出
    输出为按要求排序后的结果
例子输入
    abcdhgfe
例子输出
    hgfedcba
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10000

char str[MAX_N] = "\0";

int main()
{
    int len = 0, bor = 0, eol = 0;
    cin.getline(str, MAX_N);    // 整行读入
    len = strlen(str);
    bor = (len + 1) / 2;    // Beginning of right
    eol = len / 2;          // End of left
    for (int i = 1; i < eol; i++)
        for (int j = 0; j < i; j++)
            if (str[j] < str[i])
            {
                str[i] = str[i] ^ str[j];
                str[j] = str[i] ^ str[j];
                str[i] = str[i] ^ str[j];
            }
    for (int i = bor; i < len; i++)
        cout << str[i];
    if (len % 2)
        cout << str[eol];
    for (int i = 0; i < eol; i++)
        cout << str[i];
    return 0;
}
