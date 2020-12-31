/*****
����
    ������ά�ռ��е�n���㣨������10����,���n��������֮��ľ���,���������ɴ�С����������������
    �꼰����֮��ľ��롣
��������
    ����������У���һ�а���һ������n��ʾ��ĸ������ڶ��а���ÿ���������(���궼������)����������
    ��Χ��0��100�����������в�����������ͬ�ĵ㡣
�������
    ���ڴ�СΪn���������ݣ����n*(n-1)/2�и�ʽ���µľ�����Ϣ��
    (x1,y1,z1)-(x2,y2,z2)=����
    ���о��뱣�����������2λ��
��������
    4
    0 0 0 1 0 0 1 1 0 1 1 1
�������
    (0,0,0)-(1,1,1)=1.73
    (0,0,0)-(1,1,0)=1.41
    (1,0,0)-(1,1,1)=1.41
    (0,0,0)-(1,0,0)=1.00
    (1,0,0)-(1,1,0)=1.00
    (1,1,0)-(1,1,1)=1.00
��ʾ
    ע�⣺
    ð�������������������,ѡ������Ϳ�������(qsort��sort)��Ҫ�������������ж��⴦��
    ʹ��ð������ʱҪע��߽�����Ĵ���,��֤�Ƚϵ��������������鷶Χ��
    1. ����һ������е�������(x1,y1,z1)��(x2,y2,z2)����(x1,y1,z1)������������Ӧ�����ڵ�(x2,y2,z2)��ǰ�档
        �������룺
        2
        0 0 0 1 1 1
        ����ǣ�
        (0,0,0)-(1,1,1)=1.73
        ����������룺
        2
        1 1 1 0 0 0
        ���Ӧ���ǣ�
        (1,1,1)-(0,0,0)=1.73
    2. ��������Ե�p1,p2��p3,p4�ľ�����ͬ��������������������п�ǰ�ĵ�ԡ�
        �������룺
        3
        0 0 0 0 0 1 0 0 2
        ����ǣ�
        (0,0,0)-(0,0,2)=2.00
        (0,0,0)-(0,0,1)=1.00
        (0,0,1)-(0,0,2)=1.00
        ��������ɣ�
        3
        0 0 2 0 0 1 0 0 0
        �����Ӧ���ǣ�
        (0,0,2)-(0,0,0)=2.00
        (0,0,2)-(0,0,1)=1.00
        (0,0,1)-(0,0,0)=1.00
*****/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAX_N 20

struct Point
{
    int x;
    int y;
    int z;
} points[MAX_N];

struct PointPair
{
    int p1;
    int p2;
    double d;
} pairs[MAX_N * MAX_N];

bool cmp(PointPair a, PointPair b)
{
    if (a.d == b.d)
        return a.p1 < b.p1;
    return a.d > b.d;
}

int main()
{
    int n = 0, n_pair = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y >> points[i].z;
        for (int j = 0; j < i; j++)
        {
            pairs[n_pair].p1 = j;
            pairs[n_pair].p2 = i;
            pairs[n_pair++].d = sqrt(pow(points[i].x - points[j].x, 2.) \
                                     + pow(points[i].y - points[j].y, 2.) \
                                     + pow(points[i].z - points[j].z, 2.));
        }
    }
    sort(pairs, pairs + n_pair, cmp);
    for (int i = 0; i < n_pair; i++)
        cout << "(" << points[pairs[i].p1].x << "," << points[pairs[i].p1].y << "," << points[pairs[i].p1].z
            << ")-(" << points[pairs[i].p2].x << "," << points[pairs[i].p2].y << "," << points[pairs[i].p2].z
            << ")=" << fixed << setprecision(2) << pairs[i].d << endl;
    return 0;
}
