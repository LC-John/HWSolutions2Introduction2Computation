/*****
描述
    菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。
    给出一个正整数a，要求菲波那契数列中第a个数是多少。
关于输入
    第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a(1 <= a <= 20)
关于输出
    n行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a个数的大小
例子输入
    4
    5
    2
    19
    1
例子输出
    5
    1
    4181
    1
提示
    可用数组实现
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

int main()
{
    int fib[MAX_N] = {1, 1}, n_fib = 2, n = 0, idx = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> idx;
        if (idx > n_fib)
            for (int j = n_fib; j < idx; j++)
                fib[j] = fib[j-1] + fib[j-2];
        cout << fib[idx-1] << endl;
    }
    return 0;
}
