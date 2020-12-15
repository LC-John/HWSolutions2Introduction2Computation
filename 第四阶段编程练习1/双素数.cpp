/*****
描述
    学习了计算概论课之后，我们知道整数在计算机中是以二进制存储的。数学兴趣小组最近在研究质数，他们想知道，
    素数的二进制表示有什么规律，比如：素数的二进制表示中1的个数是不是素数。我们给二进制表示中1的个数仍然是
    素数的素数，取名为“双素数”。现在请你写出一个程序，统计不大于n的正整数中有多少个“双素数”。
关于输入
    输入多行，每行一个整数，即正整数n。（n<=12345）
关于输出
    输出多行，每行一个整数，即对应的不大于n的正整数中“双素数”的个数
例子输入
    3
例子输出
    1
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 12355

bool is_prime[MAX_N] = {false};

int cnt1(unsigned int num)
{
    int cnt = 0;
    for (; num > 0; num = num >> 1)
        cnt += num & 1;
    return cnt;
}

int main()
{
    int n = 0, last_n = -1;
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < MAX_N; i++)
        if (is_prime[i])
            for (int j = i + i; j < MAX_N; j += i)
                is_prime[j] = false;
    while (cin >> n)
    {
        int cnt = 0;
        for (int i = 0; i <= n; i++)
            if (is_prime[i] && is_prime[cnt1(i)])
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
