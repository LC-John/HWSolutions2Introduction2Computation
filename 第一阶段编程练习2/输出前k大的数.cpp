/*****
����
    ����һ�����飬���鳤��С��1000��ͳ��ǰk��������Ұ���k�����Ӵ�С�����
��������
    ������һ��n��ʾ����ĳ��ȣ�Ȼ������������n�������������һ��k��
�������
    �������ǰk�����
��������
    10
    4 5 6 9 8 7 1 2 3 0
    5
�������
    9
    8
    7
    6
    5
*****/

#include <iostream>
//#include <algorithm>
using namespace std;

#define MAX_N 1010

int main()
{
    int num[MAX_N] = {0}, n = 0, k = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    cin >> k;
    // ֱ��ʹ�ÿ⺯��sort����
    //sort(num, num+n);
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (num[i] > num[j])
            {
                num[i] = num[i] ^ num[j];
                num[j] = num[i] ^ num[j];
                num[i] = num[i] ^ num[j];
            }
    for (int i = n-1; i >= n-k; i--)
        cout << num[i] << endl;
    return 0;
}
