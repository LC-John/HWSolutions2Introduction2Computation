/*****
描述
    程序中保存了七种水果的名字，要求用户输入一个与水果有关的句子。程序在已存储的水果名字中搜索，
    以判断句子中是否包含七种水果的名称。如果包含，则用词组"Brussels sprouts"替换句子中出现的水
    果单词，并输出替换后的句子。如果句子中没有出现这些水果的名字，则输出"You must not enjoy fruit.".
    假设七种水果的名字为：apples, bananas, peaches, cherries, pears, oranges, strawberries.
关于输入
    输入有多行，每行是一个字符串。每一行输入中只会有一个水果名称，不会存在一行输入包括多种水果名
    称或重复水果名称的情况。
关于输出
    如果包含水果单词，则用词组"Brussels sprouts"替换句子中出现的水果单词，并输出替换后的句子。如
    果句子中没有出现这些水果的名字，则输出"You must not enjoy fruit.".
例子输入
    I really love peaches on my cereal.
    I’d rather have a candy bar
    apples are wonderful with lunch
例子输出
    I really love Brussels sprouts on my cereal.
    You must not enjoy fruit.
    Brussels sprouts are wonderful with lunch
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 10000

char str[MAX_LEN] = "\0";
const int n_fruit = 7;
char fruit[n_fruit][MAX_LEN] = {"apples", "bananas", "peaches", "cherries", "pears", "oranges", "strawberries"};

int main()
{
    while(cin.getline(str, MAX_LEN))
    {
        bool flag = false;
        for (int i = 0; i < n_fruit; i++)
        {
            char* pos = strstr(str, fruit[i]);  // 找到子串位置
            if (!pos)
                continue;
            flag = true;
            for (char *c = str; c != pos; c += 1)
                cout << *c;
            cout << "Brussels sprouts";
            cout << pos + strlen(fruit[i]) << endl;
            break;
        }
        if (!flag)
            cout << "You must not enjoy fruit." << endl;
    }
    return 0;
}
