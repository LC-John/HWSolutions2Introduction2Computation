/*****
描述
    有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一
    天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输
    出第m天得流感的人数。
关于输入
    第一行一个数字n，n不超过100，表示有n*n的宿舍房间。
    接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得
    流感的人。
    接下来的一行是一个整数m，m不超过100.
关于输出
    输出第m天，得流感的人数
例子输入
    5
    ....#
    .#.@.
    .#@..
    #....
    .....
    4
例子输出
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
