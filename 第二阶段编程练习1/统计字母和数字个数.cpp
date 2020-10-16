/*****
描述
    药学院附属小学于2018年将编程正式加入校园课程，要求所有课程均要结合编程进行教学，于是，老师药驰盖给同学们布置了一道家庭作业，
    要求利用编程，统计出一串乱码中的大写字母个数，小写字母个数以及数字个数，但药老师自己不会编程，所以麻烦你帮忙写一份作为标准答
    案。
关于输入
    一行长度为n的英文字母（0 < n <=256）
关于输出
    一行，大写字母个数，小写字母个数以及数字个数，均为整数，两数之间用一个空格隔开
例子输入
    AbCdEf gHiJkL 123456
例子输出
    6 6 6
提示
    输入的乱码中包含空格
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000

int main()
{
    char str[MAX_N];
    int n_upper = 0, n_lower = 0, n_digit = 0;
    while(cin >> str)
    {
        for (int i = 0; str[i] != '\0'; i++)    // 字符串总是以'\0'结尾
            if (str[i] <= 'Z' && str[i] >= 'A')
                n_upper++;
            else if (str[i] <= 'z' && str[i] >= 'a')
                n_lower++;
            else if (str[i] <= '9' && str[i] >= '0')
                n_digit++;
    }
    cout << n_upper << " " << n_lower << " " << n_digit;
    return 0;
}
