/*****
描述
    如上图所示，由正整数1, 2, 3, ...组成了一棵无限大的二叉树。从某一个结点到根结点（编号是1的结点）都有一条唯一的路径，
    比如从10到根结点的路径是(10, 5, 2, 1)，从4到根结点的路径是(4, 2, 1)，从根结点1到根结点的路径上只包含一个结点1，因
    此路径就是(1)。对于两个结点x和y，假设他们到根结点的路径分别是(x1, x2, ... ,1)和(y1, y2, ... ,1)（这里显然有x = x1，
    y = y1），那么必然存在两个正整数i和j，使得从xi 和 yj开始，有xi = yj , xi + 1 = yj + 1, xi + 2 = yj + 2,... 现在
    的问题就是，给定x和y，要求xi（也就是yj）。
关于输入
    输入只有一行，包括两个正整数x和y，这两个正整数都不大于1000。
关于输出
    输出只有一个正整数xi。
例子输入
    10 4
例子输出
    2
*****/

#include<iostream>
using namespace std;

int func(int x, int y)
{
	if (x == y) // 找到最近的共同的父节点
		return x;
	else if (x > y)             // x比y深
		return func(x / 2, y);  // x向上走一层
	else if (x < y)             // y比x深
		return func(x, y / 2);  // y向上走一层
}

int main()
{
	int x = 0, y = 0;
	cin >> x >> y;
	cout << func(x, y);
	return 0;
}
