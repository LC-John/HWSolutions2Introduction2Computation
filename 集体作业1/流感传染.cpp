/*****
����
    ��һ���׸���Ⱥס������״���������ڣ�������Ϊn*n�ľ���ÿ�����Ϊһ�����䣬���������ס�ˣ�Ҳ���ܿ��š��ڵ�һ
    �죬��Щ��������˵������У��Ժ�ÿ�죬�����е��˻�ʹ���ھӴ�Ⱦ�����У����Ѿ��ò��Ĳ��䣩���շ��䲻�ᴫȾ������
    ����m������е�������
��������
    ��һ��һ������n��n������100����ʾ��n*n�����᷿�䡣
    ��������n�У�ÿ��n���ַ�����.����ʾ��һ��÷���ס�Ž������ˣ���#����ʾ�÷�����ţ���@����ʾ��һ��÷���ס�ŵ�
    ���е��ˡ�
    ��������һ����һ������m��m������100.
�������
    �����m�죬�����е�����
��������
    5
    ....#
    .#.@.
    .#@..
    #....
    .....
    4
�������
    16
*****/

#include <iostream>
using namespace std;

#define MAX_N 200

int room[MAX_N][MAX_N] = {0};
int n = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    char c;
    int m = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            switch(c)
            {
                case '.': room[i][j] = 0; break;
                case '@': room[i][j] = 1; break;
                case '#': room[i][j] = -1; break;
                default: break;
            }
        }
    cin >> m;
    for (int _day = 1; _day < m; _day++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (room[i][j] <= _day && room[i][j] > 0)
                    for (int d = 0; d < 4; d++)
                        if (room[i + dx[d]][j + dy[d]] == 0)
                            room[i + dx[d]][j + dy[d]] = _day + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (room[i][j] > 0)
                cnt++;
    cout << cnt;
    return 0;
}
