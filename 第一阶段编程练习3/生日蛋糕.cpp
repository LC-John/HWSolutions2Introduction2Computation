/*****
����
    ���յ����������ò�ݮ��СF��ѵ����г���״��ȫ��ͬ�����飬����ÿһ���϶���һ����ݮ������԰Ѳ�ݮ����һ���㣬�п��ʱ�������в�ݮ�������ܷ��г�������ͬ�����飿
��������
    ��һ�а���һ������t��ʾ��t��������ݡ�
    ÿ���������һ�У�����7��������r x1 y1 x2 y2 x3 y3��r��ʾ����뾶��(x1,y1)(x2,y2)(x3,y3)��ʾ������ݮ��λ�ã���Բ��Ϊ������ԭ�㣩��
�������
    ��ÿ���������һ�С�
    ����ܹ��г�ȫ�ȵ����鲢��ÿ������һ����ݮ�����"Yes"���������"No"
��������
    2
    2 1 1 -1 1 0 -1
    10 0 9 1 8 -1 8
�������
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
