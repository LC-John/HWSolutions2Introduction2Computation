/*****
描述
    输入两个数，输出其最小公倍数。
关于输入
    输入两个数（100以内），用逗号隔开。
关于输出
    输出它们的最小公倍数。
例子输入
    12,45
例子输出
    180
提示
    先用辗转相除法求出最大公约数,然后求得公倍数。注意此题输入是用逗号隔开而不是用空格隔开。
    辗转相除法：设两数为a、b(a>b），求a和b最大公约数(a，b）的步骤如下：用b除a，得a=bq......r1(0≤r1）。
    若r1=0，则（a，b)=b；若r1≠0，则再用r1除b，得b=r1q......r2 (0≤r2）.若r2=0，则（a，b)=r1，若r2≠0，
    则继续用r2除r1，……如此下去，直到能整除为止。其最后一个非零除数即为（a，b）
*****/

#include <iostream>
using namespace std;

int func(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return func(b, a % b);
}

int main()
{
	int a, b;
	char c;
	cin >> a >> c >> b;
	if (a < b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	cout << a * b / func(a, b) << endl;
}
