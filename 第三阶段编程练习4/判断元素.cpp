/*****
描述
    有一个集合M是这样生成的：
    (1) 已知 k 是集合 M 的元素；
    (2) 如果 y 是 M 的元素，那么， 2y+1 和 3y+1 都是 M 的元素；
    (3) 除了上述二种情况外，没有别的数能够成为 M 的一个元素。
    问题：任意给定 k 和 x，请判断 x 是否是 M 的元素。这里的 k是无符号整数，x 不大于 100000，
    如果是，则输出YES，否则，输出 NO
关于输入
    输入整数 k 和 x, 逗号间隔。
关于输出
    如果是，则输出 YES，否则，输出NO
例子输入
    0,22
例子输出
    YES
*****/

#include <iostream>
#include <cstring>
using namespace std;

bool check_M(int y, int x, bool *visit)
{
    bool ret = false;
    if (y > x)          // 超出搜索范围，终止
        return false;
    if (y == x)         // 搜索到，终止
        return true;
    if (visit[y])       // 搜索过的情况，终止
        return false;
    ret = ret || check_M(2 * y + 1, x, visit);
    visit[2 * y + 1] = true;
    if (ret)
        return true;
    ret = ret || check_M(3 * y + 1, x, visit);
    visit[3 * y + 1] = true;
    return ret;
}

int main()
{
    int k = 0, x = 0;
    bool *visit = NULL;
    char c = '\0';
    cin >> k >> c >> x;
    visit = new bool[x * 4];    // 动态分配数组给指针
    memset(visit, 0, sizeof(bool) * x * 4);
    if (check_M(k, x, visit))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
