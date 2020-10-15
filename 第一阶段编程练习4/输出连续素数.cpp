/*****
描述
    编写程序，将大于整数m且紧靠m的k个素数输出（k小于10）。
关于输入
    输入为一行，包括两个整数，第一个为整数m，第二个为个数k
关于输出
    输出为一行，即满足条件的k个素数
例子输入
    3 4
例子输出
    5 7 11 13
*****/

#include <iostream>
using namespace std;

#define MAX_N 10000

int prime[MAX_N] = {2, 3, 5, 7}, n_prime = 4;

bool check_prime(int num)
{
    for (int i = 0; i < n_prime && prime[i] < num; i++)
        if (num % prime[i] == 0)
            return false;
    if (prime[n_prime-1] < num)
        prime[n_prime++] = num;
    return true;
}

int main()
{
    int m, k;
    bool whitespace = false;
    cin >> m >> k;
    for (int i = prime[n_prime-1] + 2; i <= m; i += 2)
        check_prime(i);
    for (int i = m + 1; k > 0; i++)
        if (check_prime(i))
        {
            if (whitespace)
                cout << " ";
            else
                whitespace = true;
            cout << i;
            k--;
        }
    return 0;
}
