/*****
描述
    如下所示的由正整数数字构成的三角形:
    7
    3 8
    8 1 0
    2 7 4 4
    4 5 2 6 5
    从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，
    和最大的路径称为最佳路径。你的任务就是求出最佳路径上的数字之和。
    注意：路径上的每一步只能从一个数走到下一层上和它最近的下边（正下方）的数或者右边（右下方）
    的数。
关于输入
    第一行为三角形高度100>=h>=1，同时也是最底层边的数字的数目。
    从第二行开始，每行为三角形相应行的数字，中间用空格分隔。
关于输出
    最佳路径的长度数值。
例子输入
    5
    7
    3 8
    8 1 0
    2 7 4 4
    4 5 2 6 5
    或
    1
    8
例子输出
    30
    或
    8
提示
    如何采用动态规划的思想，对问题进行分解。
*****/

#include <iostream>
using namespace std;

#define MAX_N 110

int dp[MAX_N][MAX_N] = {0};
int val[MAX_N] = {0};

int main()
{
    int n = 0, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
        {
            cin >> val[j];
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] += val[j];
        }
    for (int i = 0; i <= n; i++)
        res = max(res, dp[n][i]);
    cout << res;
    return 0;
}
