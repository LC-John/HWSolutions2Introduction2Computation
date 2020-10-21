/*****
描述
    寻找素数对，要求这两个素数之差的绝对值还是素数。请在[m,n]范围内（包含m和n；其中，m和n都是正整
    数，且m小于n）寻找这样的素数对。输出所有满足条件的素数对(k1,K2)；如果不存在，则输出 NULL。
假定n的最大值不超过 200000
关于输入
正整数m 和 n，以逗号间隔。
关于输出
    输出[m,n]范围内的素数对序列，每一对素数均以(k1,k2)的形式表示，偶对之间以分号间隔。其中，k1小于
    k2；要求，k1较小的偶对先输出，在k1相等的情况下，k2较小的偶对先输出。如果没有，输出NULL
例子输入
    1,15
例子输出
    (2,5)
    (2,7)
    (2,13)
    (3,5)
    (5,7)
    (11,13)
*****/

#include <iostream>
using namespace std;

#define MAX_N 300000

int prime[MAX_N] = {2, 3, 5, 7}, is_prime[MAX_N] = {0, 0, 1, 1, 0, 1, 0, 1}, n_prime = 4;

int main()
{
    int m = 0, n = 0;
    char c;
    bool output_null = true;
    cin >> m >> c >> n;
    for (int i = 11; i <= n; i += 2)
    {
        bool flag = true;
        for (int j = 0; j < n_prime; j++)
            if (i % prime[j] == 0)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            prime[n_prime++] = i;
            is_prime[i] = 1;
        }
    }
    for (int i = m; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (is_prime[i] && is_prime[j] && is_prime[j - i])
            {
                output_null = false;
                cout << "(" << i << "," << j << ")" << endl;
            }
    if (output_null)
        cout << "NULL";
    return 0;
}
