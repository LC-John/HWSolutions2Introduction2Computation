/*****
����
    �������Ϊn(n<100)�����統n=3ʱ������int a[3][3]������int b[3][3]��
    ������������û����롣����µľ���c=a+b��
�����ʽ��
    c00 c01 c02
    c10 c11 c12
    c20 c21 c22
    ÿ��������֮����1���ո�
��������
    �������n
    ����a:
    a00 a01 a02
    a10 a11 a12
    a20 a21 a22
    ����b:
    b00 b01 b02
    b10 b11 b12
    b20 b21 b22
�������
    ����c��
    c00 c01 c02
    c10 c11 c12
    c20 c21 c22
��������
    3
    1 2 3
    4 5 6
    7 8 9
    7 8 9
    4 5 6
    1 2 3
�������
    8 10 12
    8 10 12
    8 10 12
��ʾ
    ע�⣺���ʱÿ��������пո�
*****/

#include <iostream>
using namespace std;

#define MAX_N 200

int a[MAX_N][MAX_N] = {0};
int b[MAX_N][MAX_N] = {0};
int n = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
    for (int i = 0; i < n; i++)
    {
        cout << a[i][0] + b[i][0];
        for (int j = 1; j < n; j++)
            cout << " " << a[i][j] + b[i][j];
        cout << endl;
    }
    return 0;
}
