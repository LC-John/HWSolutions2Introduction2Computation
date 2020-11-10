/*****
����
    ��n��Ӳ���ų�һ�ţ�ÿ��Ӳ������һ�����ֱ�ʶ�����ļ�ֵ��ÿ��Ҫ�������߻������ұ��ó�һ��Ӳ�ҡ��ܹ���k�Σ�дһ���㷨��ʹ���õ���Ӳ�ҵļ�ֵ�����
��������
    ����������У���һ��Ϊn�� k��
    �ڶ��а���n�����֣���ʾn��Ӳ�ҵļ�ֵ��
    1 <= k <= n <= 100000
    ����Ӳ�ҵļ�ֵ����0�Ҳ�����10000.
�������
    ��������õ���k��Ӳ�����ļ�ֵ�͡�
��������
    6 3
    5 4 3 2 1 6
�������
    15
��ʾ
    ����߿�ʼ����ȡ����Ӳ�ң��ұ�ȡһ��Ӳ�Ҽ��ɡ�
*****/

#include <iostream>
using namespace std;

#define MAX_N 100010

int val[MAX_N] = {0};

/*
�ҵ�n��Ӳ���У�����n-k��Ӳ�ҵ���С��ֵmin_sum_k
��n��Ӳ�ҵ��ܺ�sum��ȥmin_sum_k����
*/

int main()
{
    int n = 0, k = 0;
    int sum_k = 0, min_sum_k = 0, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n - k; i++)
    {
        cin >> val[i];
        sum_k += val[i];
        min_sum_k += val[i];
        sum += val[i];
    }
    for (int i = n - k; i < n; i++)
    {
        cin >> val[i];
        sum += val[i];
        sum_k += val[i] - val[i - (n - k)];
        if (sum_k < min_sum_k)
            min_sum_k = sum_k;
    }
    cout << sum - min_sum_k;
    return 0;
}
