/*****
描述
    把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
    （用K表示）5，1，1和1，5，1 是同一种分法。
关于输入
    第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。
    1<=M，N<=10。
关于输出
    对输入的每组数据M和N，用一行输出相应的K。
例子输入
    1
    7 3
例子输出
    8
*****/

#include <iostream>
using namespace std;

int func(int m, int n)  // m个苹果，n个盘子
{
    if (n > m)  // 盘子比苹果多
        return func(m, m);
    if (m == 0)     // 没有苹果了
        return 1;   // 只有空着盘子一种放法
    if (n == 0)     // 没有盘子了
        return 0;   // 不存在放法
    return func(m, n-1) // 空着一个盘子的方法
        + func(m-n, n);  // 每个盘子各放一个苹果的方法
}

int main()
{
    int n_case;
    cin >> n_case;
    while(n_case--)
    {
        int M = 0, N = 0;
        cin >> M >> N;
        cout << func(M, N) << endl;
    }
    return 0;
}
