/*****
描述
    有一棵树二叉树T，T中每个节点均有一个值，定义树的和为树上所有节点的值的和。
    已知T是以1节点为根的树。如果当前在x点，则按照下述规则继续向下走：
    1.  若x是叶子节点，则目的已达到，停留在x。
    2.  若x只有左子树，则走到x的左孩子。
    3.  若x只有右子树，则走到x的右孩子。
    4.  若x同时有左子树和右子树，考察左子树的和和右子树的和，走到和较大的那一边,若和相同，则走到左子树。
    现在给出这样的T，请你编写程序求出从1节点开始，按照上述规则最后会停留在哪一个点。
关于输入
    题目由多组数据构成，数据第一行是数据组数T(1<=T<=100)，表示有T组数据。
    接下来是T组数据，每组数据第一行是一个整数n，表示树的节点数量。接下来一行是n个由空格隔开的整数，依次表
    示节点1~n的值(1<=val<=100)。接下来n-1行，每行有三个数a,b,type，其中a,b均在[1,n]之间，type=0表示b是a
    的左孩子，type=1表示b是a的右孩子。
    数据保证给出的是一棵合法的二叉树。
关于输出
    对于每组数据，输出一行，即最后会停留的节点位置。
例子输入
    2
    3
    1 2 3
    1 2 0
    1 3 1
    6
    1 1 1 1 1 4
    1 2 0
    2 3 0
    2 6 1
    3 4 0
    3 5 1
例子输出
    3
    6
*****/

#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_N 200

struct Node
{
	int l, r;
	int n;
	int val;
} a[MAX_N];

void calval(int k)
{
	if (a[k].l == 0 && a[k].r == 0)
		return;
	if (a[k].l != 0)
    {
		calval(a[k].l);
		a[k].val += a[a[k].l].val;
	}
	if (a[k].r != 0)
    {
		calval(a[k].r);
		a[k].val += a[a[k].r].val;
	}
	return;
}

int search(int k)
{
	if (a[k].l == 0 && a[k].r == 0)
		return k;
	if (a[k].l == 0)
		return search(a[k].r);
	if (a[k].r == 0)
		return search(a[k].l);
	if (a[a[k].l].val < a[a[k].r].val)
		return search(a[k].r);
	return search(a[k].l);
}

int main()
{
	int T, n;
	cin >> T;
	while (T--)
    {
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].val;
			a[i].l = a[i].r = 0;
			a[i].n = i;
		}
		for (int i = 0; i < n - 1; ++i)
		{
			int y1, y2, type;
			cin >> y1 >> y2 >> type;
			if (type == 0)
				a[y1].l = y2;
			else
				a[y1].r = y2;
		}
		calval(1);
		cout << search(1) << endl;
	}
	return 0;
}
