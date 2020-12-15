/*****
描述
    给出一个数S，请你把它分解为若干个不同的正整数{a1,a2,...,an}之和，
    即a1+a2+...+an=S，并且使得a1*a2*...*an最大。
关于输入
    一个正整数S(5<=S<=1000)
关于输出
    输出分解后的结果，按从小到大的顺序输出。
例子输入
    7
例子输出
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
