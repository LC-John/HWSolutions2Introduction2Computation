/*****
描述
    在一片保护林中，护林员想要盖一座房子来居住，但他不能砍伐任何树木。
    现在请你帮他计算：保护林中所能用来盖房子的矩形空地的最大面积。
关于输入
    输入：
    保护林用一个二维矩阵来表示，长宽都不超过20（即<=20）。
    第一行是两个正整数m,n，表示矩阵有m行n列。
    然后是m行，每行n个整数，用1代表树木，用0表示空地。
关于输出
    输出：
    一个正整数，表示保护林中能用来盖房子的最大矩形空地面积。
例子输入
    4 5
    0 1 0 1 1
    0 1 0 0 1
    0 0 0 0 0
    0 1 1 0 1
例子输出
    5
提示
    子矩阵边长可以为1，也就是说：
    0 0 0 0 0
    依然是一个可以盖房子的子矩阵。
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

int arr[MAX_N][MAX_N] = {0};
int m = 0, n = 0;

/*
// 暴力运算的复杂度是O(n^3*m^3)
// 20^6完全在接受范围内
// 因此可以直接暴力求解
*/

int main()
{
    int res = -1;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int ii = i; ii < m; ii++)
                for (int jj = j; jj < n; jj++)
                {
                    bool flag = false;
                    for (int x = i; x <= ii; x++)
                    {
                        for (int y = j; y <= jj; y++)
                            if (arr[x][y])
                            {
                                flag = true;
                                break;
                            }
                        if (flag)
                            break;
                    }
                    if (!flag && (jj - j + 1) * (ii - i + 1) > res)
                        res = (jj - j + 1) * (ii - i + 1);
                }
    cout << res;
    return 0;
}
