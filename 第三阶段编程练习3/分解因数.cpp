/*****
����
    ����һ��������a��Ҫ��ֽ�����ɸ��������ĳ˻�����a = a1 * a2 * a3 * ... * an������
    1 < a1 <= a2 <= a3 <= ... <= an���������ķֽ�������ж��١�ע�⵽a = aҲ��һ�ַֽ⡣
��������
    ��1���ǲ������ݵ�����n���������n�����롣ÿ���������ռ1�У�����һ��������a (1 < a < 32768)
�������
    n�У�ÿ�������Ӧһ�����롣���Ӧ��һ����������ָ������Ҫ��ķֽ������
��������
    2
    2
    20
�������
    1
    4
*****/

#include <iostream>
using namespace std;

int func(int n, int start)
{
	int res = 0;
	for (int i = start; i * i <= n; i++)
		if (n % i == 0)
			res += func(n / i, i);
	return res + 1; // ���������Ҳ��һ�ַֽⷽ��
}

int main()
{
	int n_case, n;
	cin >> n_case;
	while (n_case--) {
		cin >> n;
		cout << func(n, 2) << endl;
	}
	return 0;
}
