/*****
描述
    给定两个整数集合，输出交集，输出时，按元素从小到大的顺序输出，以逗号间隔。
    注意：给定的集合中可能有重复元素，但输出的交集中不能有重复元素。如果没有交集，则输出 NULL
    例：
    集合A：1,3,5,6,10,6,8,11
    集合B: 2,4,8,6,10,6,12,13
    那么，输出为：
    6,8,10
关于输入
    2行，每行表示一个集合的元素序列，元素之间以逗号间隔，假定每个集合不超出200个元素。
关于输出
    两个集合的交集，按元素从小到大输出，以逗号间隔。如果没有交集，则输出 NULL
例子输入
    1,3,5,6,10,6,8,11
    2,4,8,6,10,6,12,13
例子输出
    6,8,10
提示
    集合中元素的个数请自己想办法确定
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000

int A[MAX_N] = {0}, B[MAX_N] = {0};
int na = 0, nb = 0;

int main()
{
    bool flag = false;
    int last = 0xffffffff;
    do
        cin >> A[na++];
    while(cin.get() != '\n');
    do
        cin >> B[nb++];
    while(cin.get() != '\n');
    sort(A, A + na);
    sort(B, B + nb);
    for (int i = 0, j = 0; i < na && j < nb;)
        if (A[i] == B[j])
        {
            if (A[i] == last)
            {
                i++;
                j++;
                continue;
            }
            if (flag)
                cout << ",";
            cout << A[i];
            last = A[i];
            i++;
            j++;
            flag = true;
        }
        else if (A[i] < B[j])
            i++;
        else
            j++;
    if (!flag)
        cout << "NULL";
    return 0;
}
