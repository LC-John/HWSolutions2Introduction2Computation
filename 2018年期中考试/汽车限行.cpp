/*****
描述
    为了缓解交通压力、减少空气污染，B市市政府决定在工作日（周一至周五）对机动车进行限行，每辆机动车每周将有一个工作日
    不能出行，但周末不限行。假设该政策从2000年1月1日起开始执行。限行安排为：
    尾号为1和6：周一限行
    尾号为2和7：周二限行
    尾号为3和8：周三限行
    尾号为4和9：周四限行
    尾号为5、0和字母：周五限行
    已知2000年1月1日为周六，现在给出一些日期和车牌号，求问该机动车在该天是否限行。
关于输入
    输入第一行为一个整数n（1<=n<=100），表示测试的组数。
    之后输入n行，每一行由一个日期和一个车牌号组成，用空格分隔。日期的格式为“YYYY-MM-DD"，例如“2000-01-23”，日期保
    证在2000年1月1日～9999年12月31日之间；车牌号的格式为6位字符串，由数字和大写字母组成，例如“A123Q6”。
关于输出
    输出共n行，对于每一组测试输出一行。如果给出的车辆在给出日期限行，则输出“yes”，否则输出“no”。
例子输入
    10
    2016-01-04 8WNVKN
    4592-11-05 JAR2RU
    2470-04-15 O54FSL
    7730-08-14 WDI3DO
    9895-01-09 1CQZ8N
    6293-10-20 V45WMK
    5304-10-11 RTDY7U
    9810-07-14 NAC5LS
    7268-11-07 PWQZ1M
    6140-09-20 HJR1QV
例子输出
    no
    no
    no
    no
    no
    yes
    no
    no
    no
    no
提示
    请考虑闰年。
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 10

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
    int n = 0;
    cin >> n;
    for (int _case = 0; _case < n; _case++)
    {
        int y = 0, m = 0, d = 0, cnt = 0, leap = 0;
        char c = '\0', number[MAX_LEN] = "\0";
        bool ok = true;
        cin >> y >> c >> m >> c >> d >> number;
        leap = is_leap(y);
        for (int i = 2000; i < y; i++)
            if (is_leap(i))
                cnt += LEAP;
            else
                cnt += NOLEAP;
        for (int i = 1; i < m; i++)
            cnt += days[leap][i];
        cnt += d - 1;
        switch ((cnt + 6) % 7)
        {
        case 1: if (number[5] == '1' || number[5] == '6') ok = false; break;
        case 2: if (number[5] == '2' || number[5] == '7') ok = false; break;
        case 3: if (number[5] == '3' || number[5] == '8') ok = false; break;
        case 4: if (number[5] == '4' || number[5] == '9') ok = false; break;
        case 5: if (number[5] == '5' || number[5] == '0' || (number[5] >= 'A' && number[5] <= 'Z')) ok = false; break;
        default: break;
        }
        if (ok) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}
