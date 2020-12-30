/*****
����
    ��һ����������T��T��ÿ���ڵ����һ��ֵ���������ĺ�Ϊ�������нڵ��ֵ�ĺ͡�
    ��֪T����1�ڵ�Ϊ�������������ǰ��x�㣬��������������������ߣ�
    1.  ��x��Ҷ�ӽڵ㣬��Ŀ���Ѵﵽ��ͣ����x��
    2.  ��xֻ�������������ߵ�x�����ӡ�
    3.  ��xֻ�������������ߵ�x���Һ��ӡ�
    4.  ��xͬʱ�����������������������������ĺͺ��������ĺͣ��ߵ��ͽϴ����һ��,������ͬ�����ߵ���������
    ���ڸ���������T�������д���������1�ڵ㿪ʼ������������������ͣ������һ���㡣
��������
    ��Ŀ�ɶ������ݹ��ɣ����ݵ�һ������������T(1<=T<=100)����ʾ��T�����ݡ�
    ��������T�����ݣ�ÿ�����ݵ�һ����һ������n����ʾ���Ľڵ�������������һ����n���ɿո���������������α�
    ʾ�ڵ�1~n��ֵ(1<=val<=100)��������n-1�У�ÿ����������a,b,type������a,b����[1,n]֮�䣬type=0��ʾb��a
    �����ӣ�type=1��ʾb��a���Һ��ӡ�
    ���ݱ�֤��������һ�úϷ��Ķ�������
�������
    ����ÿ�����ݣ����һ�У�������ͣ���Ľڵ�λ�á�
��������
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
�������
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
