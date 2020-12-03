/*****
描述
    将一个大于1的正整数分解为质因数的积
关于输入
    一个大于1的正整数，如，72
关于输出
    分解为质因数的积后输出，如
    72=2*2*2*3*3
例子输入
    72
例子输出
    72=2*2*2*3*3
*****/

#include <cstdio>
#include <cstring>

#define MAX_N 1000000

bool is_prime[MAX_N] = {false}; // 筛法

int main()
{
    int num = 0;
    bool flag = true;
    scanf("%d", &num);
    printf("%d=", num);
    memset(is_prime+2, 0xff, sizeof(bool)*(MAX_N-2));
    for (int i = 2; i <= num; i++)
        if (is_prime[i])    // 发现质数
        {
            for (int j = i + i; j <= num; j += i)
                is_prime[j] = false;
            while (num % i == 0)    // 利用当前质数分解
            {
                num /= i;
                if (flag)
                    flag = false;
                else
                    printf("*");
                printf("%d", i);
            }
        }
    return 0;
}
