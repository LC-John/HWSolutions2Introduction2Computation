/*****
����
    ����һ�����������������������ľ���ֵ��
��������
    һ�У�һ��������
�������
    �������������ľ���ֵ��������λС��
��������
    1.23
    -3.14
�������
    1.23
    3.14
��ʾ
    Ҫ�����������λС��������
    ����#include�������ӣ��� iomanip ������
    ʹ�����µ������������
    cout << setiosflags(ios::fixed) << setprecision(2) << x << endl;
*****/

#include <iostream>
#include <iomanip>
//#include <cstdio>
//#include <cmath>
using namespace std;

int main()
{
    float a;
    cin >> a;
    if (a < 0)
        a = -a;
    cout << setiosflags(ios::fixed) << setprecision(2) << a;
    // ʹ��printf��fabs�ķ����������аٶ����
    //printf("%.2f", fabs(a));
    return 0;
}
