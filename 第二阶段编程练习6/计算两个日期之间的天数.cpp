/*****
描述
    给定两个年月日，计算之间的天数.
    比如2010-1-1和2010-1-3 之间差2天。
    year=1,2,...,3000.
    补充：
    闰年是：(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)，
    闰年的2月份有29天。
关于输入
    第一行
    startYear startMonth startDay
    第二行
    endYear endMonth endDay
关于输出
    输出只有一行是两个日期之间的天数
例子输入
    2008 1 1
    2009 1 1
例子输出
    366
*****/

#include <iostream>
using namespace std;

#define LEAP 366
#define NOLEAP 365
#define MONTH 12

int days[2][MONTH+1] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    // 平年
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}     // 闰年
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
    for (int y = sy; y <= ey; y++)  // 从起始年的1月1日到终止年的12月31日共有多少天
        if (is_leap(y))
            cnt += LEAP;
        else
            cnt += NOLEAP;
    leap = is_leap(sy);             // 去除起始年中起始月日之前的天数
    for (int m = 1; m < sm; m++)
        cnt -= days[leap][m];
    cnt -= sd;
    leap = is_leap(ey);             // 去除终止年中终止月日之后的天数
    for (int m = em; m <= MONTH; m++)
        cnt -= days[leap][m];
    cnt += ed;
    cout << cnt;
    return 0;
}
