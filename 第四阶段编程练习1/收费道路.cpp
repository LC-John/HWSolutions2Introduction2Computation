/*****
描述
    一个由m条道路组成的网络连接着N个城市（编号为1到N）。不同城市之间可能有多条道路。其中有一些道路是收费的。对于一条从城市ai到城市bi的收费道路i，有两种方式付款：
    1、预先付款：在城市ci（ci可能和ai相同，也可能不同。也就是说，在通过从ai到bi的道路i之前，曾经经过城市ci，在那里预先把这段路费付清）
    2、之后付款：在城市bi（即通过这段道路i之后，在目的城市bi进行付款）
    第1种情况要付Pi元，第2种情况要付Ri元。其中Pi≤Ri。
    写一个程序寻找最低花费从城市1到城市N的路线。
关于输入
    输入的第1行包含整数N和m。接下来的m行每行都表示1条道路，给出了道路的5个值，ai，bi，ci，Pi，Ri (1 ≤ i ≤ m)，5个整数之间用一个或多个空格隔开。所有的值都是整数，1 ≤ m, N ≤ 10, 0 ≤ Pi , Ri ≤ 100, Pi ≤ Ri (1 ≤ i ≤ m)。
关于输出
    输出只有1行，即从城市1到城市N最少的费用。如果从城市1无法到达城市N，输出impossible。
例子输入
    4 5
    1 2 1 10 10
    2 3 1 30 50
    3 4 3 80 80
    2 1 2 10 10
    1 3 2 10 50
例子输出
    110
提示
    深度优先搜索
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
