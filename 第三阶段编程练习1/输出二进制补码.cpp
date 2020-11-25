/*****
描述
输入若干int型整数，输出每个整数的二进制补码。
关于输入
输入有若干行，除最后一行外，每行包含一个int型整数。最后一行仅包含一个不定的字母，标志着输入结束。我们保证输入的整数不超出int型变量的表示范围
关于输出
对于每个输入的整数，输出一行，即该整数的补码表示。
例子输入
1

7

200

-45

h
例子输出
00000000000000000000000000000001

00000000000000000000000000000111

00000000000000000000000011001000

11111111111111111111111111010011
*****/

#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_LEN 100
#define INT_LEN 32

int main()
{
    char str[MAX_LEN] = "\0";
    while(cin >> str)
    {
        int num = 0, bin[MAX_LEN] = {0};
        if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
            break;
        sscanf(str, "%d", &num);
        for (int idx = 0; idx < INT_LEN; num = num >> 1)
            bin[idx++] = num & 1;
        for (int i = INT_LEN - 1; i >= 0; i--)
            cout << bin[i];
        cout << endl;
    }
    return 0;
}
