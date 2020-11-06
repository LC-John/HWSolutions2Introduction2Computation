/*****
描述
    在边长为9的正方形培养皿中，正中心位置有m个细菌。假设细菌的寿命仅一天，但每天可繁殖10个后代，而且这10个
    后代，有两个分布在原来的单元格中，其余的均匀分布在其四周相邻的八个单元格中。求经过n(1≤n≤4)天后，细菌
    在培养皿中的分布情况。
关于输入
    输入为两个整数，第一个整数m表示中心位置细菌的个数（2≤m≤30），第二个整数n表示经过的天数（1≤m≤4）。
关于输出
    输出九行九列整数矩阵，每行的整数之间用空格分隔。整个矩阵代表n天后细菌在培养皿上的分布情况。
例子输入
    2 1
例子输出
    0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0
    0 0 0 2 2 2 0 0 0
    0 0 0 2 4 2 0 0 0
    0 0 0 2 2 2 0 0 0
    0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 20
#define L 9
#define DIR_N 8

// 交换缓冲区计算
int swp[2][MAX_N][MAX_N] = {0}; // 下标从1起进行存储，留出一圈边界便于操作
int cur = 0;

int dx[DIR_N] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[DIR_N] = {1, -1, 0, 0, 1, 1, -1, -1};

int main()
{
    int m = 0, n = 0, mid = (L + 1) / 2;
    cin >> m >> n;
    memset(swp, 0, sizeof(swp));
    swp[cur][mid][mid] = m;
    for (int _day = 0; _day < n; _day++)
    {
        int nxt = 1 - cur;
        memset(swp[nxt], 0, sizeof(int) * MAX_N * MAX_N);
        for (int i = 1; i <= L; i++)
            for (int j = 1; j <= L; j++)
                if (swp[cur][i][j] > 0)
                {
                    swp[nxt][i][j] += swp[cur][i][j] * 2;
                    for (int d = 0; d < DIR_N; d++)
                        swp[nxt][i+dx[d]][j+dy[d]] += swp[cur][i][j];
                }
        cur = nxt;
    }
    for (int i = 1; i <= L; i++)
    {
        cout << swp[cur][i][1];
        for (int j = 2; j <= L; j++)
            cout << " " << swp[cur][i][j];
        cout << endl;
    }
    return 0;
}
