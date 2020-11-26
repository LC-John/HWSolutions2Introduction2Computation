/*****
描述
    “大师兄，师傅又被妖怪抓走了！”，沙师弟说道。悟空听到这个消息，便立刻前去救师傅。可是当悟空来到妖怪洞府
    时，发现妖怪给自己设了一个阵，只有成功破解这个阵，悟空才能救出师傅。请帮悟空判断他能否救出师傅。
关于输入
    输入第一行是两个数字m和n，表示该阵为m*n大小（0 < m,n <= 50，m为行，n为列）。接下来是一个m*n的矩阵表示这
    个阵。其中0为该阵中可走的路，1为墙（即不能走的位置），2为悟空的位置，3为师傅的位置。悟空只有四个可行的行
    走方向：即，上、下、左、右，不能斜对角线穿越。每行输入的数据之间都是空格间隔。
关于输出
    输出只有一行，"Yes"或"No"表示悟空是否可以成功救出师傅（悟空能走到师傅的位置即可救出师傅）。
例子输入
    8 7
    1 1 1 1 1 1 3
    1 0 0 0 0 0 0
    1 0 1 1 1 1 1
    1 0 0 0 1 1 1
    1 1 1 0 0 0 1
    1 0 0 0 1 0 1
    1 0 1 1 1 0 1
    2 0 1 1 1 0 0
例子输出
    Yes
*****/

#include <iostream>
using namespace std;

#define MAX_N 100
#define ROAD 0
#define WALL 1
#define VISITED 2
#define GOAL 3

int arr[MAX_N][MAX_N] = {0}, m = 0, n = 0;

bool func(int i, int j)
{
    bool ret = false;
    int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};
    for (int d = 0; d < 4; d++)
    {
        int _i = i + di[d], _j = j + dj[d];
        if (_i < 0 || _i >= m || _j < 0 || _j >= n) // 出界
            continue;
        if (arr[_i][_j] == GOAL)    // 找到
            return true;
        if (arr[_i][_j] != ROAD)      // 不是路
            continue;
        arr[_i][_j] = VISITED;
        ret = ret || func(_i, _j);
        if (ret)
            return ret;
    }
    return ret;
}

int main()
{
    int x = 0, y = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == VISITED)
            {
                x = i;
                y = j;
            }
        }
    if (func(x, y))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
