/*****
描述
    生日蛋糕上有三棵草莓，小F想把蛋糕切成形状完全相同的三块，并且每一块上都有一个草莓。你可以把草莓看成一个点，切块的时候不能切中草莓。请问能否切成满足相同的三块？
关于输入
    第一行包含一个整数t表示有t组测试数据。
    每组测试数据一行，包含7个整数：r x1 y1 x2 y2 x3 y3，r表示蛋糕半径，(x1,y1)(x2,y2)(x3,y3)表示三个草莓的位置（以圆心为坐标轴原点）。
关于输出
    对每组数据输出一行。
    如果能够切成全等的三块并且每块上有一个草莓，输出"Yes"，否则输出"No"
例子输入
    2
    2 1 1 -1 1 0 -1
    10 0 9 1 8 -1 8
例子输出
    Yes
    No
*****/

#include<iostream>;
#include<cmath>;
using namespace std;

#define MAX_N 10

bool check_angle(double x1, double y1, double x2, double y2)
{
    return (x1*x2 + y1*y2) / (sqrt(x1*x1 + y1*y1) * sqrt(x2*x2 + y2*y2)) > -0.5;
}

bool check_outside(double r, double x, double y)
{
    return sqrt(x*x + y*y) > r;
}

bool check_center(double x, double y)
{
    return x*x + y*y == 0;
}

int main()
{
	int t;
	cin >> t;
	for(int case_ = 0; case_ < t; case_++)
    {
        double r, x[MAX_N], y[MAX_N];
        int n = 3;
        bool flag = false, flag2 = true;
		cin >> r;
		for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;
            if (flag2 && !check_angle(x[i], y[i], x[j], y[j]))
                flag2 = false;
            if (check_outside(r, x[i], y[i]) || check_center(x[i], y[i]))
            {
                flag = true;
                break;
            }
        }
        flag |= flag2;
        if (flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
	return 0;
}
