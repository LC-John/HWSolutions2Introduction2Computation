/*****
描述
    给定一个N*N的矩阵，假设从左上角开始，旋转着依次输出矩阵中的每个元素，那么，一个5*5的矩阵，会按照下面的顺序输出。
    当然，这是个作业题。现在要求更进一步，假设根据上述方案，我们需要从开头（左上角）和结尾（中心，也就是原来的顺序中最后一
    个数）按照一正一反的顺序依次输出矩阵中的元素。也就是说，5*5的矩阵，会按照下面的顺序输出
    给定你该矩阵，请按照上述方式输出矩阵中的每个元素
关于输入
    第一行一个数N
    接下来N行，每行N个数（用空格分隔），描述了该N*N的矩阵
    数据范围：1<=N<=100
关于输出
    一行，N*N个数，用空格分隔。按照上述顺序输出的矩阵的每个元素
例子输入
    4
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
例子输出
    1 10 2 11 3 7 4 6 8 5 12 9 16 13 15 14
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000
#define MASK 0x7fffffff

int arr[MAX_N][MAX_N] = {0};
int out[MAX_N * MAX_N] = {0};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    for (int cur = 0, d = 0, i = 0, j = 0; cur < n * n; cur++)
    {
        int _i = i + dx[d], _j = j + dy[d];
        out[cur] = arr[i][j];
        // cout << arr[i][j] << " " << i << " " << j << endl;
        arr[i][j] = MASK;
        if (_i < 0 || _i >= n || _j < 0 || _j >= n || arr[_i][_j] == MASK)
        {
            d = (d + 5) % 4;
            _i = i + dx[d];
            _j = j + dy[d];
            // cout << "TURN" << endl;
        }
        i = _i;
        j = _j;
    }
    // for (int i = 0; i < n * n; i++)
    //     cout << out[i] << " ";
    if (n == 1) // 边界条件，特判n为1的情况
    {
        cout << out[0];
        return 0;
    }
    cout << out[0] << " " << out[n * n - 1];
    for (int i = 1; i < n * n / 2; i++)
        cout << " " << out[i] << " " << out[n * n - 1 - i];
    if (n % 2)
        cout << " " << out[n * n / 2];
    return 0;
}
