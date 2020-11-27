/*****
����
    ����һ������+��-��*��/��()������������ʽ������������ʽ��ֵ��
    ������ʽ���㣺
    1��û�����Ų�ƥ����������������Ƕ�׵�����
    2����������Ϊ���������迼��������
    3��û�зǷ����ʽ��Ҳû���������������
    4�����в�����������Ϊ���ͼ��㣬�����Ƿ�����С�������
    5���м��������ս�����ᳬ��int�ı�ʾ��Χ
��������
    �����У�ÿ��Ϊһ���Ϸ�������������ʽ
�������
    �����У�Ϊ��Ӧ��������
��������
    1+3+5
    5*(3+7)
    -(-4/(1+3))*5-1*2*3
�������
    9
    50
    -1
*****/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX_LEN 1000

char a[MAX_LEN] = "\0";

int matched(int l, int r)
{
	int cnt = 1;
	for (int i = r - 1; i >= l; i--)
    {
		if (a[i] == ')')
			cnt++;
		else if (a[i] == '(')
			cnt--;
		if (cnt == 0)
			return i;
	}
	return 0;
}

int compute(int l, int r)
{
	for (int i = r; i >= l; i--)
    {
		if (a[i] == ')')
			i = matched(l, i);
		if (a[i] == '+')
			return compute(i + 1, r) + compute(l, i - 1);
		if (a[i] == '-')
			return compute(l, i - 1) - compute(i + 1, r);
	}
	for (int i = r; i >= l; i--)
	{
		if (a[i] == ')')
			i = matched(l, i);
		if (a[i] == '*')
			return compute(i + 1, r) * compute(l, i - 1);
		if (a[i] == '/')
			return compute(l, i - 1) / compute(i + 1, r);
	}
	if (a[r] == ')')
		return compute(l + 1, r - 1);
	if (a[r] >= '0' && a[r] <= '9')
	{
		int ans = 0, j = 0;
		for (int i = r; i >= l; i--, j++)
			ans += pow(10.0, (double)j) * (a[i] - '0');
		return ans;
	}
	return 0;
}

int main()
{
	while (cin.getline(a, MAX_LEN))
    {
		int x = strlen(a);
		cout << compute(0, x - 1) << endl;
	}
	return 0;
}
