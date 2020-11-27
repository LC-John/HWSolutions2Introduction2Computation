/*****
描述
    现在有一个n阶正整数方阵（n<=7），现在可以对矩阵的任意一行进行左移，具体操作为：每次对于某一行
    a_i1,a_i2,…,a_in进行一次左移，最左边的元素移动到这一行的末尾，其他元素均向左移动一位，即变为
    a_i2,a_i3,…,a_in,a_i1。对某一行可以执行任意次的左移。
    现在我们的目标是：通过对矩阵的每一行进行若干次左移，使得矩阵中每列和的最大值最小。
关于输入
    输入包含多组数据。
    对于每组数据，第一行为一个正整数n（1<=n<=7），代表矩阵的阶。接下来的n行，每行n个正整数（不超过
    10000），代表这个矩阵。
    输入数据以一个-1为结尾代表输入结束。
关于输出
    对于每组数据，输出一行一个正整数，为最小的最大列和。
例子输入
    2
    4 6
    3 7
    3
    1 2 3
    4 5 6
    7 8 9
    -1
例子输出
    11
    15
*****/

#include <iostream>
using namespace std;

#define MAX_N 10

int n, arr[MAX_N][MAX_N], offset[MAX_N];
int res;

int calc()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
    {
		int tmp = 0;
		for (int j = 0; j < n; ++j)
			tmp += arr[j][(i + offset[j]) % n];
        if (ret < tmp)
            ret = tmp;
	}
	return ret;
}

void func(int idx)
{
	if (idx >= n)
    {
        int tmp = calc();
        if (res > tmp)
            res = tmp;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		offset[idx] = i;
		func(idx + 1);
	}
	return;
}

int main()
{
	while (cin >> n)
    {
        if (n < 0)
            break;
		res = 0x7fffffff;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> arr[i][j];
		func(0);
		cout << res << endl;
	}
	return 0;
}
