/*****
描述
    给定两个二进制数 a 和 b ，计算 a + b 之和，输出和的二进制表示。
关于输入
    输入有 2n + 1 行，第一行是 n，其余2n行，每两行一组，第一行是二进制数 a，第二行是二进制数 b；a 和 b 都大
    于 0 且不含前导 0 ，a、b 的位数不超过 100 位。
关于输出
    输出 n 行 a + b 的结果，用二进制表示。
例子输入
    2
    1110011
    11111111000
    1010101
    101010
例子输出
    100001101011
    1111111
提示
    对 n 的取值没有特别的限制，只需要保证 n 是自然数即可。
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000

int debug(char* str, int len)
{
    for (int i = 0; i < len; i++)
        cout << str[i];
    cout << endl;
    return 0;
}

char* str_reverse(char* str, int len)   // 翻转字符串
{
    int i = len / 2;
    if (len % 2 == 1)
        i++;
    for (; i < len; i++)
    {
        str[i] = str[i] ^ str[len-1-i];
        str[len-1-i] = str[i] ^ str[len-1-i];
        str[i] = str[i] ^ str[len-1-i];
    }
    return str;
}

int main()
{
    int n_case = 0, la = 0, lb = 0;
    char *a = NULL, *b = NULL;  // 使用指针，方便交换
    cin >> n_case;
    for (int _case = 0; _case < n_case; _case++)
    {
        char c = '0';   // 进位
        a = new char[MAX_N];
        b = new char[MAX_N];
        memset(a, 0, sizeof(char) * MAX_N);
        memset(b, 0, sizeof(char) * MAX_N);
        cin >> a >> b;
        la = strlen(a);
        lb = strlen(b);
        if (la < lb)    // 确保a的长度不小于b
        {
            char* tmp = a;
            a = b;
            b = tmp;
            la = strlen(a);
            lb = strlen(b);
        }
        a = str_reverse(a, la);  // 翻转a和b，使之低位对其
        b = str_reverse(b, lb);
        memset(b + lb, '0', sizeof(char) * (la - lb));  // 用'0'补齐b
        //debug(a, la);
        //debug(b, la);
        for (int i = 0; i < la; i++)                    // 逐位计算，用a[i] b[i] c
            switch ((a[i] - '0') + (b[i] - '0') + c)    // 计算得到该位结果和进位，存于a[i]和c
            {
                case '0': a[i] = '0'; c = '0'; break;
                case '1': a[i] = '1'; c = '0'; break;
                case '2': a[i] = '0'; c = '1'; break;
                case '3': a[i] = '1'; c = '1'; break;
            }
        if (c > '0')
            cout << c;
        for (int i = la - 1; i >= 0; i--)
            cout << a[i];
        cout << endl;
        delete[] a;
        delete[] b;
    }
    return 0;
}
