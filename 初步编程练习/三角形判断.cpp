/*****
����
    ����������������ʾ�����ߵĳ��ȣ��ж����������ܷ񹹳�һ�������Σ�����ܣ��������yes�������������no����
��������
    ���������������������ֱ��ʾ�����ߵĳ��ȡ�
�������
    yes ���� no
��������
    3 4 5
�������
    yes
*****/

#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a)
        cout << "yes";
    else
        cout << "no";
    return 0;
}
