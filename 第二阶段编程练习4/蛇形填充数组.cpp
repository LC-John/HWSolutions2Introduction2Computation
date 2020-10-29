/*****
描述
    用数字1,2,3,4,... 蛇形填充规模为n*n的方阵,蛇形填充规则见示例数组
关于输入
    输入为一行，为一个整数n，表示输出方阵的行数(n <= 15)
关于输出
    输出该方阵，相邻两个元素之间用空格间隔，每行最后一个元素后面没有空格
例子输入
    4
例子输出
    1 2 6 7
    3 5 8 13
    4 9 12 14
    10 11 15 16
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

int arr[MAX_N][MAX_N] = {0}, n = 0;

void output()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i][0];
        for (int j = 1; j < n; j++)
            cout << " " << arr[i][j];
        cout << endl;
    }
    return;
}

int main()
{
    int num = 1;
    bool flag = false;
    cin >> n;
    for (int s = 0; s < n; s++)
    {
        for (int i = 0; i <= s; i++)
            if (flag)
                arr[i][s-i] = num++;
            else
                arr[s-i][i] = num++;
        flag = !flag;
    }
    // output();
    for (int s = n; s < 2 * n - 1; s++)
    {
        for (int i = n - 1; s - i < n; i--)
            if (!flag)
                arr[i][s-i] = num++;
            else
                arr[s-i][i] = num++;
        flag = !flag;
    }
    output();
    return 0;
}
