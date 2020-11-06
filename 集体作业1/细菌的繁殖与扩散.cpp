/*****
����
    �ڱ߳�Ϊ9���������������У�������λ����m��ϸ��������ϸ����������һ�죬��ÿ��ɷ�ֳ10�������������10��
    ������������ֲ���ԭ���ĵ�Ԫ���У�����ľ��ȷֲ������������ڵİ˸���Ԫ���С��󾭹�n(1��n��4)���ϸ��
    ���������еķֲ������
��������
    ����Ϊ������������һ������m��ʾ����λ��ϸ���ĸ�����2��m��30�����ڶ�������n��ʾ������������1��m��4����
�������
    ������о�����������ÿ�е�����֮���ÿո�ָ��������������n���ϸ�����������ϵķֲ������
��������
    2 1
�������
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

// ��������������
int swp[2][MAX_N][MAX_N] = {0}; // �±��1����д洢������һȦ�߽���ڲ���
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
