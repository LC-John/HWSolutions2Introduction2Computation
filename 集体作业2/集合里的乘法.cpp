/*****
描述
    给定整数集合S和一个目标数T，判断是否可以从S中挑选一个非空子集，子集中的数相乘的乘积为T。
关于输入
    输入为两行。
    第一行为目标数T和S中的元素个数N，以空格隔开。
    第二行为S中的N个元素，以空格隔开。
    其中 N <= 16。
关于输出
    如果可以，则输出YES，否则输出NO。
例子输入
    Sample Input 1:
    12 5
    1 2 3 4 5
    Sample Input 2:
    33 5
    4 2 8 7 5
例子输出
    Sample Output 1:
    YES
    Sample Output 2:
    NO
*****/

#include <iostream>
using namespace std;

#define MAX_N 20

long long num[MAX_N] = {0}, n = 0, goal = 0;

bool func(int idx, long long mul)
{
    if (idx >= n)       // 超出范围
        return false;
    if (mul == goal)    // 找到可行的方案
        return true;
    if (func(idx + 1, mul * num[idx]))  // mul里算上第idx个数的方案
        return true;
    return func(idx + 1, mul);  // mul里不算第idx个数的方案
}

int main()
{
    cin >> goal >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    if (func(0, 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
