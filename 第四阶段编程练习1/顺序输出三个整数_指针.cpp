/*****
����
    ���������������������븡������������С�����˳�������������Ϊ�����������������
    �����Ϊ�������������Ϊ���������ұ���С�����2λ������ʹ�ò���Ϊָ��ĺ�������ɣ�������
��������
    ����Ϊ�����������Ÿ�����
�������
    ���Ϊ����С����˳�����е������ö��Ÿ�����
��������
    25��48��37
�������
    25��37��48
��ʾ
    �ޡ�
*****/

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define MAX_N 3

bool cmp(double *a, double *b)
{
    return *a < *b;
}

int main()
{
    double *num[MAX_N] = {NULL};
    for (int i = 0; i < MAX_N; i++)
    {
        if (i > 0)
        {
            char c;
            cin >> c;
        }
        num[i] = new double;
        cin >> *(num[i]);
    }
    sort(num, num + MAX_N, cmp);
    for (int i = 0; i < MAX_N; i++)
    {
        if (i > 0)
            cout << ",";
        if (*(num[i]) - int(*(num[i])) > 0)
            cout << fixed << setprecision(2) << *(num[i]);
        else
            cout << int(*(num[i]));
    }
    return 0;
}
