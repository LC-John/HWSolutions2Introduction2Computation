/*****
描述
    输入一个字符，判断是大写字母还是小写字母，是大写字母输出"upper case",是小写字母输出"lower case",如果都不是则输出"invalid input".
关于输入
    输入为一个字符
关于输出
    输出为字符的信息
例子输入
    s
例子输出
    lower case
*****/

#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    if (c <= 'Z' && c >= 'A')
        cout << "upper case";
    else if (c <= 'z' && c >= 'a')
        cout << "lower case";
    else
        cout << "invalid input";
    return 0;
}
