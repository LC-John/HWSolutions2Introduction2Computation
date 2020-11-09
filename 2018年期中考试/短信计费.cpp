/*****
描述
    用手机发短信，一般一条短信资费为0.1元，但限定每条短信的内容在70个字以内（包括70个字）。如果你所发送的一条短信超过了
    70个字，则大多数手机会按照每70个字一条短信的限制把它分割成多条短信发送。假设已经知道你当月所发送的每条短信的字数，试
    统计一下你当月短信的总资费。
关于输入
    第一行是整数n，表示当月短信总条数，其余n行每行一个整数，表示各条短信的字数。
关于输出
    当月短信总资费，单位为元，精确到小数点后1位。
例子输入
    10
    39
    49
    42
    61
    44
    147
    42
    72
    35
    46
例子输出
    1.3
*****/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAX_MSG_LEN 70.
#define EXP_PER_MSG .1

int main()
{
    int n = 0, len = 0;
    double exp = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> len;
        exp += ceil(len / MAX_MSG_LEN) * EXP_PER_MSG;
    }
    cout << fixed << setprecision(1) << exp;
    return 0;
}
