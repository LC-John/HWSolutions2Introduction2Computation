/*****
����
    ����һ����S����������ֽ�Ϊ���ɸ���ͬ��������{a1,a2,...,an}֮�ͣ�
    ��a1+a2+...+an=S������ʹ��a1*a2*...*an���
��������
    һ��������S(5<=S<=1000)
�������
    ����ֽ��Ľ��������С�����˳�������
��������
    7
�������
    3 4
*****/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX_N 1010

int nums[MAX_N] = {0};

int main()
{
	int n;
	cin >> n;
	int i = 0;
	while (n >= i + 2) {
		nums[i] = i + 2;
		n -= i + 2;
		i++;
	}
	while (n > 0) {
		for (int j = i - 1; n > 0 && j >= 0; j--, n--)
			nums[j] += 1;
	}
	for (int j = 0; j < i - 1; ++j)
		cout << nums[j] << ' ';
	cout << nums[i - 1] << endl;
	return 0;
}
