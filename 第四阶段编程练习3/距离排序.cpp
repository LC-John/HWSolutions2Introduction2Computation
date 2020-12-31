/*****
描述
    给出三维空间中的n个点（不超过10个）,求出n个点两两之间的距离,并按距离由大到小依次输出两个点的坐
    标及它们之间的距离。
关于输入
    输入包括两行，第一行包含一个整数n表示点的个数，第二行包含每个点的坐标(坐标都是整数)。点的坐标的
    范围是0到100，输入数据中不存在坐标相同的点。
关于输出
    对于大小为n的输入数据，输出n*(n-1)/2行格式如下的距离信息：
    (x1,y1,z1)-(x2,y2,z2)=距离
    其中距离保留到数点后面2位。
例子输入
    4
    0 0 0 1 0 0 1 1 0 1 1 1
例子输出
    (0,0,0)-(1,1,1)=1.73
    (0,0,0)-(1,1,0)=1.41
    (1,0,0)-(1,1,1)=1.41
    (0,0,0)-(1,0,0)=1.00
    (1,0,0)-(1,1,0)=1.00
    (1,1,0)-(1,1,1)=1.00
提示
    注意：
    冒泡排序满足下面的性质,选择排序和快速排序(qsort或sort)需要对下面的情况进行额外处理
    使用冒泡排序时要注意边界情况的处理,保证比较的两个数都在数组范围内
    1. 对于一行输出中的两个点(x1,y1,z1)和(x2,y2,z2)，点(x1,y1,z1)在输入数据中应出现在点(x2,y2,z2)的前面。
        比如输入：
        2
        0 0 0 1 1 1
        输出是：
        (0,0,0)-(1,1,1)=1.73
        但是如果输入：
        2
        1 1 1 0 0 0
        输出应该是：
        (1,1,1)-(0,0,0)=1.73
    2. 如果有两对点p1,p2和p3,p4的距离相同，则先输出在输入数据中靠前的点对。
        比如输入：
        3
        0 0 0 0 0 1 0 0 2
        输出是：
        (0,0,0)-(0,0,2)=2.00
        (0,0,0)-(0,0,1)=1.00
        (0,0,1)-(0,0,2)=1.00
        如果输入变成：
        3
        0 0 2 0 0 1 0 0 0
        则输出应该是：
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
