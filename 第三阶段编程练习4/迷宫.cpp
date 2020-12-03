/*****
描述
    一天Extense在森林里探险的时候不小心走入了一个迷宫，迷宫可以看成是由n * n的格点组成，每个格点只有2种状态，
    .和#，前者表示可以通行后者表示不能通行。同时当Extense处在某个格点时，他只能移动到东南西北(或者说上下左右)
    四个方向之一的相邻格点上，Extense想要从点A走到点B，问在不走出迷宫的情况下能不能办到。如果起点或者终点有一
    个不能通行(为#)，则看成无法办到。
关于输入
    第1行是测试数据的组数k，后面跟着k组输入。每组测试数据的第1行是一个正整数n (1 <= n <= 100)，表示迷宫的规模
    是n * n的。接下来是一个n * n的矩阵，矩阵中的元素为.或者#。再接下来一行是4个整数ha, la, hb, lb，描述A处在
    第ha行, 第la列，B处在第hb行, 第lb列。注意到ha, la, hb, lb全部是从0开始计数的。
关于输出
    k行，每行输出对应一个输入。能办到则输出“YES”，否则输出“NO”。
例子输入
    2
    3
    .##
    ..#
    #..
    0 0 2 2
    5
    .....
    ###.#
    ..#..
    ###..
    ...#.
    0 0 4 0
例子输出
    YES
    NO
*****/

#include <iostream>
using namespace std;

#define ROAD '.'
#define WALL '#'

void debug_print(char** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j];
        cout << endl;
    }
}

bool dfs(char** a, int n, int curri, int currj, int tgti, int tgtj)
{
    int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
    if (curri == tgti && currj == tgtj) // 找到，终止
        return true;
    if (curri < 0 || curri >= n || currj < 0 || currj >= n) // 出界，终止
        return false;
    if (a[curri][currj] == WALL)        // 走到墙里，终止
        return false;
    a[curri][currj] = WALL;             // 走过的路设置为墙，避免重复走
    for (int d = 0; d < 4; d++)
        if (dfs(a, n, curri+di[d], currj+dj[d], tgti, tgtj))
            return true;
    return false;
}

int main()
{
    int n_case = 0;
    cin >> n_case;
    while(n_case--)
    {
        int n = 0, si = 0, sj = 0, ei = 0, ej = 0;
        char **arr = NULL;
        cin >> n;
        arr = new char*[n];             // 动态分配二维数组
        for (int i = 0; i < n; i++)
        {
            arr[i] = new char[n];
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
        cin >> si >> sj >> ei >> ej;
        // debug_print(arr, n);
        if (arr[si][sj] == WALL || arr[ei][ej] == WALL)
        {
            cout << "NO" << endl;
            continue;
        }
        if (dfs(arr, n, si, sj, ei, ej))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        for (int i = 0; i < n; i++)
            delete[] arr[i];
        delete[] arr;
    }
    return 0;
}
