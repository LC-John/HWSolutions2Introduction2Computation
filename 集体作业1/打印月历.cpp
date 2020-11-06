/*****
描述
    给定某年某月，打印出当月的月历表，月历表的输出格式如样例所示。
关于输入
    输入为一行两个整数，第一个整数是年份year（1900 ≤ year ≤ 2099），第二个整数是月份month（1 ≤ month ≤ 12）。
关于输出
    输出为月历表。
    月历表第一行为星期表头，如下所示：
    Sun Mon Tue Wed Thu Fri Sat
    注：在上行中，每个单词占4个字符位。也就是说，Sun之前有一个空格，其后每个单词之间有一个空格，最后一个单词Sat之后没有空格。
    其余各行依次是当月各天的日期，从1日开始到30日（或31日 或28日）；
    每个日期数字也占4个字符的位置，且 日期数字 与 相应的星期表头 右对齐。
    第一个日期数字之前如果需要空出星期表头，可以用  四个空格  代替一个日期数字所占的4个字符位，最后一个日期数字之后没有换行或空格。
例子输入
    2006 5
例子输出
 Sun Mon Tue Wed Thu Fri Sat

       1   2   3   4   5   6

   7   8   9  10  11  12  13

  14  15  16  17  18  19  20

  21  22  23  24  25  26  27

  28  29  30  31
提示
    1900年1月1日是星期一，可以此为基准日期。
    满足以下两个条件之一的年份为闰年：
    （1）年份能被4整除但不能被100整除
    （2）年份能被400整除
*****/

#include <cstdio>
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
    int y = 0, m = 0, cnt = 0, leap = 0;
    scanf("%d %d", &y, &m);
    leap = is_leap(y);
    for (int i = 1900; i < y; i++)
        if (is_leap(i))
            cnt += LEAP;
        else
            cnt += NOLEAP;
    for (int i = 1; i < m; i++)
        cnt += days[leap][i];
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    for (int i = 0; i < (cnt + 1) % 7; i++)
        printf("    ");
    for (int i = (cnt + 1) % 7, d = 1; d <= days[leap][m]; d++, i = (i + 1) % 7)
    {
        printf("%4d", d);
        if (i == 6)
            printf("\n");
    }
    return 0;
}
