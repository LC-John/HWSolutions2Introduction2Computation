/*****
描述
    输入一个整数，判断它能否被3，5，7整除，并输出以下信息：
    （1）能同时被3，5，7整除（直接输出3 5 7，每个数中间一个空格）；
    （2）能被其中两个数整除（输出两个数，小的在前，大的在后。例如：3 5或者 3 7或者5 7,中间用空格分隔）
    （3）能被其中一个数整除（输出这个除数）
    （4）不能被任何数整除；（输出小写字符n)
关于输入
    一个整数
关于输出
    实现题目的要求
例子输入
    21
例子输出
    3 7
*****/

#include <iostream>
using namespace std;

#define MAX_N 100 // 宏定义数组大小，也可以直接在下面写数字

int main()
{
    int div[MAX_N] = {3, 5, 7}, n_div = 3, num = 0;
    bool flag = true;
    cin >> num;
    // 这是一种可以扩展的写法，不管是多少个数，都可以用循环解决
    for (int i = 0; i < n_div; i++)
        if (num % div[i] == 0)
        {
            if (flag)
                cout << div[i];
            else
                cout << " " << div[i];
            flag = false;
        }
    if (flag)
        cout << "n";
    return 0;
}
