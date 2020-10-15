/*****
描述
    在两个正整数m和n给定的整数范围内（m 小于 n，且不包括m和n）取出各位数字之和均为k的倍数的所有数(k为正整数)，然后将这些数划分成若干个子集合，
    每个子集合中的元素满足其各位数字之和相等，请输出各个子集合, 其中  n 不大于10000。
    每个集合元素按从小到大输出，逗号间隔，如果有多个集合，则输出多行；集合中最小元素较小的在前面行输出。
    例如，m=11, n=35, k=3 则，
    12,21,30 这三个数的每位数字之和均为3，且为3的倍数
    15,24,33 这三个数的每位数字之和为6，且为3的倍数
    18,27 这二个数的每位数字之和为9，也为3的倍数
    由于三组数的最小数分别是12,15,18，于是，输出结果应为：
    12,21,30
    15,24,33
    18,27
关于输入
    一行，三个值：m,n,k，以逗号间隔
关于输出
    输出各位数之和为k的倍数的若干行，每一行中，其元素的各位数字和相等，且前面行元素的各位数字之和小于后面行元素的各位数字之和，每行的元素按增序排列，以逗号间隔。
例子输入
    11,35,3
例子输出
    12,21,30
    15,24,33
    18,27
*****/

#include <iostream>
using namespace std;

#define MAX_N 10010
#define MAX_INT 0x7fffffff

int sum[MAX_N] = {0}, min_sum = MAX_INT, max_sum = -1;

int digit_sum(int num)
{
    int res = 0;
    for (int i = num; i > 0; i /= 10)
        res += (i % 10);
    return res;
}

int main()
{
    int m, n, k;
    char ch;
    cin >> m >> ch >> n >> ch >> k;
    for (int i = m+1; i < n; i++)
    {
        sum[i] = digit_sum(i);
        if (sum[i] < min_sum)
            min_sum = sum[i];
        if (sum[i] > max_sum)
            max_sum = sum[i];
    }
    for (int i = min_sum; i <= max_sum; i++)
    {
        if (i % k > 0)
            continue;
        bool first = true;
        for (int j = m+1; j < n; j++)
            if (sum[j] == i)
            {
                if (!first)
                    cout << ",";
                else
                    first = false;
                cout << j;
            }
        cout << endl;
    }
    return 0;
}
