/*****
描述
    有n个硬币排成一排，每个硬币上用一个数字标识了它的价值。每次要你从最左边或者最右边拿出一个硬币。总共拿k次，写一个算法，使能拿到的硬币的价值和最大。
关于输入
    输入包含两行，第一行为n， k；
    第二行包含n个数字，表示n个硬币的价值。
    1 <= k <= n <= 100000
    单个硬币的价值大于0且不超过10000.
关于输出
    输出可以拿到的k个硬币最大的价值和。
例子输入
    6 3
    5 4 3 2 1 6
例子输出
    15
提示
    从左边开始连续取两个硬币，右边取一个硬币即可。
*****/

#include <iostream>
using namespace std;

#define MAX_N 100010

int val[MAX_N] = {0};

/*
找到n个硬币中，连续n-k个硬币的最小价值min_sum_k
用n个硬币的总和sum减去min_sum_k即可
*/

int main()
{
    int n = 0, k = 0;
    int sum_k = 0, min_sum_k = 0, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n - k; i++)
    {
        cin >> val[i];
        sum_k += val[i];
        min_sum_k += val[i];
        sum += val[i];
    }
    for (int i = n - k; i < n; i++)
    {
        cin >> val[i];
        sum += val[i];
        sum_k += val[i] - val[i - (n - k)];
        if (sum_k < min_sum_k)
            min_sum_k = sum_k;
    }
    cout << sum - min_sum_k;
    return 0;
}
