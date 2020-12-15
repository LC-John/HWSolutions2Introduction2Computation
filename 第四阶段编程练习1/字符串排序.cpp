/*****
描述
    将输入的字符串按字典序排序后升序输出。
关于输入
    第一行是一个正整数n，表示字符串的数量，且n<=1000。
    接下来n行每行是一个由小写字母组成的字符串，字符串的长度不会超过1000。
关于输出
    输出n行，每行输出一个字符串，要求按字典序升序输出。
例子输入
    4
    zaa
    fe
    ef
    za
例子输出
    ef
    fe
    za
    zaa
提示
    ①字典序：从两个字符串的首位开始找首个不相等的字符，按这两个字符对应的ascii值的大小确定字符串的大小关系。
    可以使用strcmp函数来确定两个字符串的字典序，返回1表示传入的第一个字符串字典序大，返回-1表示第二个字符串字
    典序大，返回0表示两个字符串相等。
    ②交换两个指针比交换两个字符串快得多
*****/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 2000
#define MAX_LEN 2000

char *str[MAX_N] = {NULL};
int n = 0;

bool cmp(char* a, char*b)
{
    if (strcmp(a, b) < 0)
        return true;
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        str[i] = new char[MAX_LEN];
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    for (int i = 0; i < n; i++)
        cout << str[i] << endl;
    return 0;
}
