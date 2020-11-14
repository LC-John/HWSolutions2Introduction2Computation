/*****
����
    ����һ������ nums����������ÿ��Ԫ�� nums[i]������ͳ�������б���С���������ֵ���Ŀ��
    ������֮������ÿ�� nums[i] �����������Ч�� j ������������ j ���� j != i �� nums[j] < nums[i]��
��������
    ��һ����һ������ n����ʾ�����С��
    ������ n �У�ÿ�б�ʾ�����е�һ������
    0 <= n <= 1000, ÿ��������int���Ա�ʾ�ķ�Χ��.
�������
    n �У�ÿ�д��������б���С�����ĸ�����
��������
    5
    8
    1
    2
    2
    3
�������
    4
    0
    1
    1
    3
*****/

#include <iostream>
using namespace std;

#define MAX_N 1010

int num[MAX_N] = {0}, n = 0;

int main()
{
    cin >> n;
    if (n == 0)
        cout << "None";
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i ++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (i != j && num[j] < num[i])
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
