/*****
����
    �й��о�����С������������ɹ������ĳ�˴�1990��1��1����ʼ�����������
    ��ɹ����������������Ժ��ĳһ�����ǡ����㡱���ǡ�ɹ������
    ע��Ҫ��������Ͳ���������������
��������
    ����Ϊ��������
    ������ �� �� ����Ϊ֮���ĳһ��
�������
    ���Ϊ����
    ����������������
    fishing
    �������ɹ������
    sleeping
��������
    1991 10 25
�������
    fishing
*****/

#include <iostream>
using namespace std;

#define LEAP 366
#define NOLEAP 365
#define MONTH 12

int days[2][MONTH+1] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

int main()
{
    int y = 0, m = 0, d = 0, cnt = 0, leap = 0;
    cin >> y >> m >> d;
    leap = is_leap(y);
    for (int i = 1990; i < y; i++)
        if (is_leap(i))
            cnt += LEAP;
        else
            cnt += NOLEAP;
    for (int i = 1; i < m; i++)
        cnt += days[leap][i];
    cnt += d - 1;
    if (cnt % 5 < 3)
        cout << "fishing";
    else
        cout << "sleeping";
    return 0;
}
