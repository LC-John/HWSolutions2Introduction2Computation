/*****
����
    ��������������Ѿ��������������A[10]��B[10]��
    ��ô���ù鲢�����˼�룬����������ϲ�����������Ϊһ���µ�����C[20]
    ���Ұ�C�������Ļ�ϡ�
��������
    ���� ÿ��ʮ��Ԫ��
�������
    һ�� �ܹ�20��Ԫ��
��������
    1 3 5 7 9 11 13 15 17 19
    2 4 6 8 10 12 14 16 18 20
�������
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10

int main()
{
    const int n = MAX_N * 2;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cout << arr[0];
    for (int i = 1; i < n; i++)
        cout << " " << arr[i];
    return 0;
}
