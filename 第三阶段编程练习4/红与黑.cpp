/*****
描述
    有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向
    相邻的四块瓷砖中的黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
关于输入
    包括多个数据集合。每个数据集合的第一行是两个整数W和H，分别表示x方向和y方向瓷砖的数量。W和H都不
    超过20。在接下来的H行中，每行包括W个字符。每个字符表示一块瓷砖的颜色，规则如下
    ‘.’：黑色的瓷砖
    ‘#’：红色的瓷砖
    ‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中仅出现一次
    当在一行中读入的是两个零时，表示输入结束。
关于输出
    对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。
例子输入
    6 9
    ....#.
    .....#
    ......
    ......
    ......
    ......
    ......
    #@...#
    .#..#.
    11 9
    .#.........
    .#.#######.
    .#.#.....#.
    .#.#.###.#.
    .#.#..@#.#.
    .#.#####.#.
    .#.......#.
    .#########.
    ...........
    11 6
    ..#..#..#..
    ..#..#..#..
    ..#..#..###
    ..#..#..#@.
    ..#..#..#..
    ..#..#..#..
    7 7
    ..#.#..
    ..#.#..
    ###.###
    ...@...
    ###.###
    ..#.#..
    ..#.#..
    0 0
例子输出
    45
    59
    6
    13
*****/

#include <iostream>
using namespace std;

#define MAX_N 30
#define RED '#'
#define BLK '.'
#define STD '@'

int count_black(char** a, int w, int h, int x, int y)
{
    const int nd = 4;
    int dx[nd] = {1, -1, 0, 0};
    int dy[nd] = {0, 0, 1, -1};
    int cnt = 0;
    if (x < 0 || y < 0 || x >= h || y >= w) // 出界，终止
        return 0;
    if (a[x][y] == RED)                     // 走到红色块，终止
        return 0;
    a[x][y] = RED;  // 将走过的黑色块设置为红色，避免重复
    cnt++;
    for (int d = 0; d < nd; d++)
        cnt += count_black(a, w, h, x+dx[d], y+dy[d]);
    return cnt;
}

int main()
{
    char **arr = NULL;
    int w = 0, h = 0;
    arr = new char*[MAX_N];
    for (int i = 0; i < MAX_N; i++)
        arr[i] = new char[MAX_N];
    while(cin >> w >> h)
    {
        if (!(w && h))
            break;
        int x = 0, y = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == STD)
                {
                    x = i;
                    y = j;
                }
            }
        cout << count_black(arr, w, h, x, y) << endl;
    }
    return 0;
}
