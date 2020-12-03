/*****
描述
    一个国家有 n 个城市，每两个城市之间都开设有航班，从城市 i 到城市 j 的航班价格为
    cost[i, j] ，而且往、返航班的价格相同。
    售货商要从一个城市出发，途径每个城市 1 次（且每个城市只能经过 1 次），最终返回出
    发地，而且他的交通工具只有航班，请求出他旅行的最小开销。
关于输入
    输入的第 1 行是一个正整数 n （3 <= n <= 15）
    然后有 n 行，每行有 n 个正整数，构成一个 n * n 的矩阵，矩阵的第 i 行第 j 列为城
    市 i 到城市 j 的航班价格。
关于输出
    输出数据为一个正整数 m，表示旅行售货商的最小开销
例子输入
    4
    0 4 1 3
    4 0 2 1
    1 2 0 5
    3 1 5 0
例子输出
    7
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 15

int cost[MAX_N][MAX_N] = {0};
int mem[1 << MAX_N][MAX_N] = {0};
bool visit[MAX_N] = {false};
int n = 0;

void dfs(int pos, int exp, int status, int n_visit)
{
    if (n_visit >= n)   // 走完所有城市，终止
    {
        exp += cost[pos][0];
        if (mem[(1 << n) - 1][0] > exp || mem[(1 << n) - 1][0] < 0)
            mem[(1 << n) - 1][0] = exp;
        return;
    }
    if (mem[status | (1 << pos)][pos] > 0 && mem[status | (1 << pos)][pos] <= exp)  // 当前子情况不是最优的，直接剪枝，终止
        return;
    else
        mem[status | (1 << pos)][pos] = exp;
    for (int i = 0; i < n; i++)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        dfs(i, exp + cost[pos][i], status | (1 << i), n_visit + 1);
        visit[i] = false;
    }
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> cost[i][j];
    memset(mem, 0xff, sizeof(mem));
	dfs(0, 0, 0, 0);
	cout << mem[(1 << n) - 1][0] << endl;
	return 0;
}
