/*****
描述
    医院某科门诊早上开两个小时。从8点开始可以排队，9点开始正式门诊，每个病人需要看10分钟(若最后剩余不足
    10分钟，则不进行门诊)，11点门诊结束。输入包含n（n<=20）个病人的到达时间（距离8点的分钟数），输出最
    终得到门诊的病人数。
关于输入
    第一行为病人数n。
    之后有n行，每行为病人到达的时间
关于输出
    一个整数：能得到门诊的病人数
例子输入
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
例子输出
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
