/*****
����
    ѧУ��һ����n��ѧ������n��ѧ����һ����m�����ѹ�ϵ��
    �����з����ڣ�ÿ������ѧ����Ҫ�������������������ѣ�����еĻ��������ڵڶ��챻��Ⱦ�ϼ��������������������ڣ���
    ÿ��������ѧ���ڵڶ��춼��Ȭ����������һ����������ԡ��ӵ������𣬿������������ѽ��ٴ�ʹ��Ⱦ�����С�
    ��ʼʱ����һ�죩��ֻ��һ��ѧ���������С����ʶ���������л��Զ�������
��������
    ��һ����������������n��m��
    ������m��ÿ������������x,y����ʾ���Ϊx��ѧ���ͱ��Ϊy��ѧ����һ�����ѡ��������ݱ�֤ÿһ�����ѹ�ϵֻ����һ�Ρ�
    ���һ������һ���������������ʼʱ�������е�ѧ���ı�š�
    n,m <= 100,000��
�������
    �������������л������
    �����������2,000,000,000������Ϊ���в�����������-1��
��������
    4 4
    1 2
    2 3
    3 4
    2 4
    1
�������
    3
��ʾ
    ��һ��1��ѧ��������2��ѧ����������
    �ڶ���2��ѧ����������������ѧ��������������1�Ŵ��������ڣ�δ�����У�
    ������3��4��ѧ��������2��ѧ���������ǡ�
    ������3��4��ѧ��Ȭ�������н�����
*****/

#include <iostream>
using namespace std;

#define MAX_D 2000000000
#define MAX_N 100100
#define MAX_M 3000

#define HEA 0   // ����
#define ILL 1   // �ò�
#define IMM 2   // ����

int stu[MAX_N][MAX_M] = {0};    // stu[i][0]��¼i�ж��ٸ���ϵ��֮���stu[i][j] (1<=j<=stu[i][0])Ϊ��i�й�ϵ��ѧ��
int status[MAX_N] = {0};        // 0������1�ò���2����
int n = 0, m = 0;
int cur = 0, ill[2][MAX_N] = {0};   // ˫����������һ��Ԫ��Ϊ����������

int main()
{
    int d = 0;
    bool flag = true;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        stu[x][++stu[x][0]] = y;
        stu[y][++stu[y][0]] = x;
    }
    cin >> ill[cur][1];
    ill[cur][0] = 1;
    while (d < MAX_D)
    {
        int nxt = 1 - cur;
        //for (int i = 1; i <= ill[cur][0]; i++)
        //    cout << ill[cur][i] << " ";
        //cout << endl;
        if (ill[cur][0] == 0)
        {
            cout << d;
            flag = false;
            break;
        }
        ill[nxt][0] = 0;
        for (int i = 1; i <= ill[cur][0]; i++)
            for (int j = 1; j <= stu[ill[cur][i]][0]; j++)
                if (status[stu[ill[cur][i]][j]] == HEA)
                {
                    ill[nxt][++ill[nxt][0]] = stu[ill[cur][i]][j];
                    status[stu[ill[cur][i]][j]] = ILL;
                }
        for (int i = 1; i <= ill[cur][0]; i++)
            for (int j = 1; j <= stu[ill[cur][i]][0]; j++)
                if (status[stu[ill[cur][i]][j]] == IMM)
                    status[stu[ill[cur][i]][j]] = HEA;
        for (int i = 1; i <= ill[cur][0]; i++)
            status[ill[cur][i]] = IMM;
        d++;
        cur = nxt;
    }
    if (flag)
        cout << -1;
    return 0;
}
