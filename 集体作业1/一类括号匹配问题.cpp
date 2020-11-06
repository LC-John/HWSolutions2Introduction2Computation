/*****
描述
    在程序设计中，常常使用小括号强调表达式的运算顺序，但是，左右小括号必须匹配。现给定一个不多于500个符号的表达式（串），
    其中可能存在多个小括号，想检查小括号的匹配问题。如果存在小括号不匹配，则输出 mismatch；如果所有小括号匹配，则按左右
    括号的匹配距离由小到大输出左、右括号的位置；若多个匹配的距离相等，则左括号先出现的匹配先输出；如果整个串中没有小括号，
    则左右位置均输出0，即 0,0； ，规定，串中第一个符号的位置为1。
    匹配距离=右括号位置 - 左括号位置。
    例如：
    输入为：    (x+y*(z-5)*(x+y))*(x+98)
    输出为：
    6,10
    12,16
    19,24
    1,17
    如果输入为  (x+y*(z-5))*x+y)
    则不匹配，因为在最后的反括号没有相匹配的正括号。因此，输出：
    mismatch
关于输入
    一串符号
关于输出
    按匹配距离的增序输出匹配对的左右位置，逗号间隔；如果距离相同，则按左括号出现的先后顺序输出；如果整个序列中出现不匹配
    现象，则输出 mismatch；
例子输入
    (x+y*(z-5)*(x+y))*(x+98)
例子输出
    6,10
    12,16
    19,24
    1,17
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 1000

char str[MAX_LEN] = "\0";
int l[MAX_LEN] = {0}, r[MAX_LEN] = {0}, d[MAX_LEN] = {0}, n = 0;
bool flag = true;

bool match()
{
    int st[MAX_LEN] = {0}, st_n = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            st[st_n++] = i;
            flag = false;
        }
        else if (str[i] == ')')
        {
            l[n] = st[--st_n];
            r[n] = i;
            d[n] = r[n] - l[n];
            n++;
            flag = false;
        }
        if (st_n < 0)
            return false;
    }
    return st_n == 0;
}

int main()
{
    cin >> str;
    if (match())
    {
        if (flag)
        {
            cout << "0,0";
            return 0;
        }
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (d[j] > d[i] || (d[j] == d[i] && l[j] > l[i]))
                {
                    l[i] = l[i] ^ l[j];
                    l[j] = l[i] ^ l[j];
                    l[i] = l[i] ^ l[j];
                    r[i] = r[i] ^ r[j];
                    r[j] = r[i] ^ r[j];
                    r[i] = r[i] ^ r[j];
                    d[i] = d[i] ^ d[j];
                    d[j] = d[i] ^ d[j];
                    d[i] = d[i] ^ d[j];
                }
        for (int i = 0; i < n; i++)
            cout << l[i] + 1 << "," << r[i] + 1 << endl;
    }
    else
        cout << "mismatch";
    return 0;
}
