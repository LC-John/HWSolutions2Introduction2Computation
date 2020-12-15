/*****
����
    һ����m����·��ɵ�����������N�����У����Ϊ1��N������ͬ����֮������ж�����·��������һЩ��·���շѵġ�����һ���ӳ���ai������bi���շѵ�·i�������ַ�ʽ���
    1��Ԥ�ȸ���ڳ���ci��ci���ܺ�ai��ͬ��Ҳ���ܲ�ͬ��Ҳ����˵����ͨ����ai��bi�ĵ�·i֮ǰ��������������ci��������Ԥ�Ȱ����·�Ѹ��壩
    2��֮�󸶿�ڳ���bi����ͨ����ε�·i֮����Ŀ�ĳ���bi���и��
    ��1�����Ҫ��PiԪ����2�����Ҫ��RiԪ������Pi��Ri��
    дһ������Ѱ����ͻ��Ѵӳ���1������N��·�ߡ�
��������
    ����ĵ�1�а�������N��m����������m��ÿ�ж���ʾ1����·�������˵�·��5��ֵ��ai��bi��ci��Pi��Ri (1 �� i �� m)��5������֮����һ�������ո���������е�ֵ����������1 �� m, N �� 10, 0 �� Pi , Ri �� 100, Pi �� Ri (1 �� i �� m)��
�������
    ���ֻ��1�У����ӳ���1������N���ٵķ��á�����ӳ���1�޷��������N�����impossible��
��������
    4 5
    1 2 1 10 10
    2 3 1 30 50
    3 4 3 80 80
    2 1 2 10 10
    1 3 2 10 50
�������
    110
��ʾ
    �����������
*****/

#include<iostream>
using namespace std;

#define MAX_N 20
#define MAX_INT_VAL 0x7fffffff

int n = 0, m = 0, minfee = MAX_INT_VAL;
int visit[MAX_N] = { 0 };
struct
{
	int a, b, c, p, r;
}road[MAX_N];

void dfs(int a, int fee)
{
	if (a == n && minfee>fee)
    {
		minfee = fee;
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (visit[road[i].b] <= 3 && road[i].a == a) {
			int b = road[i].b;
			visit[b]++;
			if ((visit[road[i].c]&&b!=road[i].c)||(visit[road[i].c]>1&&b==road[i].c)) {
				dfs(b, fee + road[i].p);
			}
			else {
				dfs(b, fee + road[i].r);
			}
			visit[b]--;
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	visit[1] = 1;
	for (int i = 1; i <= m; i++)
		cin >> road[i].a >> road[i].b >> road[i].c >> road[i].p >> road[i].r;
	dfs(1, 0);
	if (minfee == MAX_INT_VAL)
		cout << "impossible" << endl;
	else
		cout << minfee << endl;
	return 0;
}
