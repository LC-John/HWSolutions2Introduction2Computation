/*****
描述
    给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。
    我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。
关于输入
    输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
关于输出
    输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：
    已知S = s1s2...sk , T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
    s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。
例子输入
    abc
例子输出
    abc
    acb
    bac
    bca
    cab
    cba
提示
    请严格用C语言实现。
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 10

char s[MAX_LEN] = "\0";
bool visited[MAX_LEN] = {false};
int idx[MAX_LEN] = {0};

void func(int depth)
{
	if (s[depth] == '\0')
    {
		for (int i = 0; s[i] != '\0'; i++)
			cout << s[idx[i]];
		cout << endl;
		return;
	}
	for (int i = 0; s[i] != '\0'; i++)
		if (!visited[i])
		{
			visited[i] = true;
			idx[depth] = i;
			func(depth + 1);
			visited[i] = false; // 回溯
		}
	return;
}

int main()
{
	cin >> s;
	func(0);
	return 0;
}
