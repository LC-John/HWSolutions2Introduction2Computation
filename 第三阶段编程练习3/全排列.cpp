/*****
����
    ����һ���ɲ�ͬ��Сд��ĸ��ɵ��ַ������������ַ���������ȫ���С�
    ���Ǽ������Сд��ĸ��'a' < 'b' < ... < 'y' < 'z'�����Ҹ������ַ����е���ĸ�Ѿ����մ�С�����˳�����С�
��������
    ����ֻ��һ�У���һ���ɲ�ͬ��Сд��ĸ��ɵ��ַ�������֪�ַ����ĳ�����1��6֮�䡣
�������
    �������ַ������������з�ʽ��ÿ��һ�����С�Ҫ����ĸ��Ƚ�С��������ǰ�档��ĸ�����¶��壺
    ��֪S = s1s2...sk , T = t1t2...tk����S < T �ȼ��ڣ�����p (1 <= p <= k)��ʹ��
    s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp������
��������
    abc
�������
    abc
    acb
    bac
    bca
    cab
    cba
��ʾ
    ���ϸ���C����ʵ�֡�
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
			visited[i] = false; // ����
		}
	return;
}

int main()
{
	cin >> s;
	func(0);
	return 0;
}
