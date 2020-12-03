/*****
����
    ������ѧ�ж������������ʥ���ڵ�����ͼ�������¥�ٰ� n �������֪ÿ����
    ���Ŀ�ʼʱ��ͽ���ʱ�䣬������ΰ��ţ������ÿɾٰ�Ļ��ࣿ
    ��ע�����������Ŀ�ʼ����ʱ��ֱ�Ϊ��3,4��(4,5)��������������ݵģ�
��������
    ��һ������Ϊ����n (n < 100,000)����ʾ����ٰ��ĸ�����
    ����n��ÿ�������������ֱ��ǻ�Ŀ�ʼʱ��ͽ���ʱ�䣨��ֵ < 1,000,000����
�������
    ���һ��������Ϊ���ٰܾ�Ļ��������
��������
    8
    41 92
    68 160
    130 213
    151 215
    211 265
    162 234
    145 221
    80 137
�������
    2
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Interval
{
	int start;
	int end;
} intervals[100000];

bool cmp(const Interval &a, const Interval &b)
{
	return a.end < b.end || a.end == b.end && a.start < b.start;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> intervals[i].start >> intervals[i].end;
	sort(intervals, intervals + n, cmp);
	int curend = 0, res = 0;
	for (int i = 0; i < n; ++i)
    {
		if (intervals[i].start < curend)
			continue;
		res++;
		curend = intervals[i].end;
	}
	cout << res << endl;
	return 0;
}
