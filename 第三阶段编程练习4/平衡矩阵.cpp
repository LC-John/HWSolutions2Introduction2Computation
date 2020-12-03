/*****
����
    ������һ��n������������n<=7�������ڿ��ԶԾ��������һ�н������ƣ��������Ϊ��ÿ�ζ���ĳһ��
    a_i1,a_i2,��,a_in����һ�����ƣ�����ߵ�Ԫ���ƶ�����һ�е�ĩβ������Ԫ�ؾ������ƶ�һλ������Ϊ
    a_i2,a_i3,��,a_in,a_i1����ĳһ�п���ִ������ε����ơ�
    �������ǵ�Ŀ���ǣ�ͨ���Ծ����ÿһ�н������ɴ����ƣ�ʹ�þ�����ÿ�к͵����ֵ��С��
��������
    ��������������ݡ�
    ����ÿ�����ݣ���һ��Ϊһ��������n��1<=n<=7�����������Ľס���������n�У�ÿ��n����������������
    10000���������������
    ����������һ��-1Ϊ��β�������������
�������
    ����ÿ�����ݣ����һ��һ����������Ϊ��С������к͡�
��������
    2
    4 6
    3 7
    3
    1 2 3
    4 5 6
    7 8 9
    -1
�������
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
