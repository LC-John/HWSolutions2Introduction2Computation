/*****
描述
    使用1角、2角、5角硬币组成 n 角钱。
    设1角、2角、5角的硬币各用了a、b、c个，列出所有可能的a, b, c组合。
    输出顺序为，按c的值从小到大，c相同的按b的值从小到大输出。
    要求必须使用递归。
关于输入
    输入只有一个整数n（1 <= n <= 100)，代表需要组成的钱的角数。
关于输出
    输出有若干行，每行的形式为：
    i           a           b           c
    第1列i代表当前行数（行数从001开始，固定3个字符宽度，宽度不足3的用0填充），
    后面3列a, b, c分别代表1角、2角、5角硬币的个数（每个数字固定12个字符宽度，宽度不足的在左边填充空格）
例子输入
    10
例子输出
    001          10           0           0
    002           8           1           0
    003           6           2           0
    004           4           3           0
    005           2           4           0
    006           0           5           0
    007           5           0           1
    008           3           1           1
    009           1           2           1
    010           0           0           2
提示
    cout << setfill('0')可以设置填充字符为'0'；
    设完之后记得调用setfill(' ')设回空格，否则会影响后续输出。
*****/

#include <cstdio>

#define N_COIN 3

int coin[N_COIN] = {5, 2, 1}, cnt[N_COIN] = {0}, line = 0;

void func(int left, int idx)
{
    if (idx == N_COIN)
    {
        if (left == 0)
        {
            printf("%03d", ++line);
            for (int i = N_COIN - 1; i >= 0; i--)
                printf("%12d", cnt[i]);
            printf("\n");
        }
        return;
    }
    for (int i = 0; i * coin[idx] <= left; i++)
    {
        cnt[idx] = i;
        func(left - coin[idx] * i, idx + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    func(n, 0);
    return 0;
}
