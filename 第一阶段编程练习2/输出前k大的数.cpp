/*****
描述
    给定一个数组，数组长度小于1000，统计前k大的数并且把这k个数从大到小输出。
关于输入
    先输入一个n表示数组的长度，然后连续地输入n个数。最后输入一个k。
关于输出
    换行输出前k大的数
例子输入
    10
    4 5 6 9 8 7 1 2 3 0
    5
例子输出
    9
    8
    7
    6
    5
*****/

#include <iostream>
//#include <algorithm>
using namespace std;

#define MAX_N 1010

int main()
{
    int num[MAX_N] = {0}, n = 0, k = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    cin >> k;
    // 直接使用库函数sort排序
    //sort(num, num+n);
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (num[i] > num[j])
            {
                num[i] = num[i] ^ num[j];
                num[j] = num[i] ^ num[j];
                num[i] = num[i] ^ num[j];
            }
    for (int i = n-1; i >= n-k; i--)
        cout << num[i] << endl;
    return 0;
}
