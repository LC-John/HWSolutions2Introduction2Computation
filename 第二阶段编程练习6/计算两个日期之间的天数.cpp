/*****
����
    �������������գ�����֮�������.
    ����2010-1-1��2010-1-3 ֮���2�졣
    year=1,2,...,3000.
    ���䣺
    �����ǣ�(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)��
    �����2�·���29�졣
��������
    ��һ��
    startYear startMonth startDay
    �ڶ���
    endYear endMonth endDay
�������
    ���ֻ��һ������������֮�������
��������
    2008 1 1
    2009 1 1
�������
    366
*****/

#include <iostream>
using namespace std;

#define LEAP 366
#define NOLEAP 365
#define MONTH 12

int days[2][MONTH+1] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    // ƽ��
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}     // ����
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
    int sy = 0, sm = 0, sd = 0, ey = 0, em = 0, ed = 0;
    int cnt = 0, leap = 0;
    cin >> sy >> sm >> sd >> ey >> em >> ed;
    for (int y = sy; y <= ey; y++)  // ����ʼ���1��1�յ���ֹ���12��31�չ��ж�����
        if (is_leap(y))
            cnt += LEAP;
        else
            cnt += NOLEAP;
    leap = is_leap(sy);             // ȥ����ʼ������ʼ����֮ǰ������
    for (int m = 1; m < sm; m++)
        cnt -= days[leap][m];
    cnt -= sd;
    leap = is_leap(ey);             // ȥ����ֹ������ֹ����֮�������
    for (int m = em; m <= MONTH; m++)
        cnt -= days[leap][m];
    cnt += ed;
    cout << cnt;
    return 0;
}
