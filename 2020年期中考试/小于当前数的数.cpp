/*****
描述
    给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
    换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i]。
关于输入
    第一行是一个整数 n，表示数组大小。
    接下来 n 行，每行表示数组中的一个数。
    0 <= n <= 1000, 每个数都在int可以表示的范围内.
关于输出
    n 行，每行代表数组中比它小的数的个数。
例子输入
    5
    8
    1
    2
    2
    3
例子输出
    4
    0
    1
    1
    3
*****/

#include <iostream>
using namespace std;

#define MAX_N 1010

int num[MAX_N] = {0}, n = 0;

int main()
{
    cin >> n;
    if (n == 0)
        cout << "None";
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i ++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (i != j && num[j] < num[i])
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
