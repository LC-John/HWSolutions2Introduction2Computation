/*****
描述
    一个十进制自然数,它的七进制与九进制表示都是三位数，且七进制与九进制的三位数码表示顺序正好相反。编程求此自然数,并输出显示.
    输入为1时，输出此自然数的十进制表达式；输入为2时，输出此自然数的七进制表达式；输入为3时，输出此自然数的九进制表达式。
关于输入
    输入为1，2，3中的一个数。
关于输出
    输出一行。
    输出为十进制或七进制或九进制数
例子输入
    1
例子输出
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10

int seven[MAX_N] = {0};
int nine[MAX_N] = {0};
int num = 0;


int main()
{
    int num_start = 1 * 9 * 9;
    int num_end = 6 * 7 * 7 + 6 * 7 + 6;
    int choice;
    for (num = num_start; num < num_end; num++)
    {
        memset(seven, 0, sizeof(seven));
        memset(nine, 0, sizeof(nine));
        for (int i = 0, tmp = num; tmp > 0; i++, tmp /= 7)
            seven[i] = tmp % 7;
        for (int i = 0, tmp = num; tmp > 0; i++, tmp /= 9)
            nine[i] = tmp % 9;
        if (seven[0] == nine[2] && seven[1] == nine[1] && seven[2] == nine[0])
            break;
    }
    cin >> choice;
    switch(choice)
    {
    case 1: cout << num; break;
    case 2:
        for (int i = 2; i >= 0; i--)
            cout << seven[i];
        break;
    case 3:
        for (int i = 2; i >= 0; i--)
            cout << nine[i];
        break;
    default: break;
    }
    return 0;
}
