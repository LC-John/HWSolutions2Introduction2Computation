/*****
描述
    编写程序，读入一段英文(英文中不包含标点)，将所有单词的顺序倒排并输出，其中单词以空格分隔。
关于输入
    输入为一个字符串（字符串长度最大为100）
关于输出
    输出为按要求排续后的字符串
例子输入
    I am a student
例子输出
    student a am I
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 200

char str[MAX_N] = "\0";
int len = 0;

int main()
{
    cin.getline(str, MAX_N);
    len = strlen(str);
    for (int l = len - 1; l >= 0; l--)
        if (str[l] == ' ')  // l右侧为一个单词
        {
            str[l] = '\0';  // 将str[l]标记，此时直接输出l左侧的部分，会到l为止
            cout << str+l+1 << " "; // 输出l右侧的单词
        }
    cout << str;     // 输出最左的单词
    return 0;
}
