/*****
����
    ������������,�����������
��������
    ����Ϊһ�У�������������
�������
    ���Ϊ����������
��������
    10 20 56
�������
    56
*****/

#include <iostream>
//#include <cmath>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    // ����ע��Ϊ͵����������ͬѧ�����аٶ����
    //cout << max(a, max(b, c));
    if (a < b)
        a = b;
    if (a < c)
        a = c;
    cout << a;
    return 0;
}
