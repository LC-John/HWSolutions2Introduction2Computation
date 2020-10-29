/*****
����
    ҽԺĳ���������Ͽ�����Сʱ����8�㿪ʼ�����Ŷӣ�9�㿪ʼ��ʽ���ÿ��������Ҫ��10����(�����ʣ�಻��
    10���ӣ��򲻽�������)��11������������������n��n<=20�������˵ĵ���ʱ�䣨����8��ķ��������������
    �յõ�����Ĳ�������
��������
    ��һ��Ϊ������n��
    ֮����n�У�ÿ��Ϊ���˵����ʱ��
�������
    һ���������ܵõ�����Ĳ�����
��������
    10
    5
    10
    160
    180
    20
    110
    145
    70
    100
    200
�������
    8
*****/

#include<iostream>
using namespace std;

#define MAX_N 100
#define MAX_TIME 180
#define START_TIME 60
#define TIME_PER_PATIENT 10

int main()
{
	int n = 0;
	int arrival[MAX_N] = {0};
	int num = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arrival[i];

	for (int a = 0; a < n - 1; a++)
		for (int b = a + 1; b < n; b++)
			if (arrival[a] > arrival[b])
			{
				arrival[a] = arrival[a] ^ arrival[b];
				arrival[b] = arrival[a] ^ arrival[b];
				arrival[a] = arrival[a] ^ arrival[b];
			}

    for (int i = 0, t = START_TIME; t <= MAX_TIME - TIME_PER_PATIENT && num < n; t++)
		if (t >= arrival[num])
		{
			num++;
			t += TIME_PER_PATIENT - 1;
		}
		else
			t++;
	cout << num;
	return 0;
}
