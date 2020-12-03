/*****
描述
    假设你给出两个已经经过排序的数组A[10]与B[10]，
    那么利用归并排序的思想，将两个数组合并并且再排序为一个新的数组C[20]
    并且把C输出的屏幕上。
关于输入
    两行 每行十个元素
关于输出
    一行 总共20个元素
例子输入
    1 3 5 7 9 11 13 15 17 19
    2 4 6 8 10 12 14 16 18 20
例子输出
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10

int main()
{
    const int n = MAX_N * 2;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cout << arr[0];
    for (int i = 1; i < n; i++)
        cout << " " << arr[i];
    return 0;
}
