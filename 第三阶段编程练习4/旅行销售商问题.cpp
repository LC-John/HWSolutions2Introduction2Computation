/*****
����
    һ�������� n �����У�ÿ��������֮�䶼�����к��࣬�ӳ��� i ������ j �ĺ���۸�Ϊ
    cost[i, j] ����������������ļ۸���ͬ��
    �ۻ���Ҫ��һ�����г�����;��ÿ������ 1 �Σ���ÿ������ֻ�ܾ��� 1 �Σ������շ��س�
    ���أ��������Ľ�ͨ����ֻ�к��࣬����������е���С������
��������
    ����ĵ� 1 ����һ�������� n ��3 <= n <= 15��
    Ȼ���� n �У�ÿ���� n ��������������һ�� n * n �ľ��󣬾���ĵ� i �е� j ��Ϊ��
    �� i ������ j �ĺ���۸�
�������
    �������Ϊһ�������� m����ʾ�����ۻ��̵���С����
��������
    4
    0 4 1 3
    4 0 2 1
    1 2 0 5
    3 1 5 0
�������
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
    if (n_visit >= n)   // �������г��У���ֹ
    {
        exp += cost[pos][0];
        if (mem[(1 << n) - 1][0] > exp || mem[(1 << n) - 1][0] < 0)
            mem[(1 << n) - 1][0] = exp;
        return;
    }
    if (mem[status | (1 << pos)][pos] > 0 && mem[status | (1 << pos)][pos] <= exp)  // ��ǰ������������ŵģ�ֱ�Ӽ�֦����ֹ
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
