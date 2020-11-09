/*****
描述
    中国有句俗语叫“三天打鱼两天晒网”。某人从1990年1月1日起开始“三天打鱼两
    天晒网”，问这个人在以后的某一天中是“打鱼”还是“晒网”。
    注意要区分闰年和不是闰年的两种情况
关于输入
    输入为三个整数
    按照年 月 日 输入为之后的某一天
关于输出
    输出为单词
    如果今天渔夫打鱼就是
    fishing
    如果今天晒网就是
    sleeping
例子输入
    1991 10 25
例子输出
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
