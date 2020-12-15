/*****
描述
    一个等差数列是指以增序排列后，相邻的两个数后一个与前一个数之差值恒定。规定一个等差数列中的数不应少于3个。任给 n ( 2 < n < 5000)
    个正整数，请判断可否从中选择子集构成等差数列。若能，则选出满足条件的最大子集合（即，元素个数最多），并按从小到大输出子集中的元素，
    逗号间隔。若有多个子集同时满足最大，则取差值最大的子集；若同时有多个子集满足集合大小最大，且差值也相等，则取起始元素最大的子集。
    如果没有满足条件的子集合，则输出 NO.
    例如，有10个元素：20,14,6,15,22,7,23,8,18,25
    从6开始的最长等差数列是：6,7,8 和 6,14,22
    从7开始的最长等差数列是：7,15,23
    从8开始的最长等差数列是：8,14,20 和 8,15,22
    从14开始的最长等差数列是：14,18,22
    从15开始的最长等差数列是：15,20,25
    从18开始的最长等差数列是：18,20,22
    上述7个最长序列中，长度都为3。按差值看，6,14,22 和 7,15,23 同时最大，但 7 > 6，因此，结果应该选 7,15,23
关于输入
    2行：
    第1行，n，表示整数个数；
    第2行，n 个正整数，空格间隔；
关于输出
    按增序输出最长等差数列子集，逗号间隔。
例子输入
    10
    20 14 6 15 22 7 23 8 18 25
例子输出
    7,15,23
*****/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define MAX_N 5050

int num[MAX_N];
int length[MAX_N][MAX_N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	sort(num, num + n);
	int maxn = 0, v1, v2;
	for (int i = 1; i < n; ++i) {
		int p = 0;
		for (int j = 0; j < i; ++j) {
			length[j][i] = 2;
			while (p < j && num[p] + num[i] < 2 * num[j])
				p++;
			if (num[p] + num[i] == 2 * num[j])
				length[j][i] = length[p][j] + 1;
			if (length[j][i] > maxn ||
				length[j][i] == maxn && num[i] - num[j] >= num[v1] - num[v2]) {
				maxn = length[j][i];
				v1 = i;
				v2 = j;
			}
		}
	}
	int i = 0, j = 0;
	while (true) {
		while (j < n && num[j] == num[i])
			j++;
		if (j - i > maxn) {
			maxn = j - i;
			v1 = v2 = i;
		}
		if (j == n)
			break;
		i = j;
	}
	if (maxn < 3) {
		cout << "NO" << endl;
	} else {
		int val1 = num[v1];
		int dif = val1 - num[v2];
		cout << val1 - dif * (maxn - 1);
		for (int i = 0; i < maxn - 1; ++i)
			cout << ',' << val1 - dif * (maxn - 2 - i);
		cout << endl;
	}
	return 0;
}
