/*****
描述
    给你一个字符串 text，该字符串由若干被空格包围的单词组成。每个单词由一个或者多个小写英文字母组成，
    并且两个单词之间至少存在一个空格。
    请你重新排列空格，使每对相邻单词之间的空格数目都  相等  ，并尽可能  最大化  该数目。如果不能重新平
    均分配所有空格，请  将多余的空格放置在字符串末尾  ，这也意味着输出的字符串应当与原字符串的长度相等。
关于输入
    一行由小写英文字母和空格组成的字符串。
    字符串长度不超过1000，至少包含一个单词。
关于输出
    一行和原字符串长度相等的字符串。
例子输入
      this   is  a sentence
例子输出
    this   is   a   sentence
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_L 1010

char str[MAX_L] = "\0";

int main()
{
    int len = 0, n_space = 0, n_word = 0, n_print_space = 0, n_print_space_suffix = 0;
    bool flag = true;
    cin.getline(str, MAX_L);
    len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] == ' ')
        {
            n_space++;
            str[i] = '\0';
        }
        else if (str[i + 1] == ' ' || str[i + 1] == '\0')
            n_word++;
    if (n_word <= 1)
    {
        n_print_space = 0;
        n_print_space_suffix = n_space;
    }
    else
    {
        n_print_space = n_space / (n_word - 1);
        n_print_space_suffix = n_space % (n_word - 1);
    }
    for (int i = 0; i < len; i++)
        if (str[i] >= 'a' && str[i] <= 'z' && (i == 0 || str[i - 1] == '\0'))
        {
            if (flag)
                flag = false;
            else
                for (int j = 0; j < n_print_space; j++)
                    cout << " ";
            cout << str + i;
        }
    for (int j = 0; j < n_print_space_suffix; j++)
            cout << " ";
    return 0;
}
