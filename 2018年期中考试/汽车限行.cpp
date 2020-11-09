/*****
����
    Ϊ�˻��⽻ͨѹ�������ٿ�����Ⱦ��B�������������ڹ����գ���һ�����壩�Ի������������У�ÿ��������ÿ�ܽ���һ��������
    ���ܳ��У�����ĩ�����С���������ߴ�2000��1��1����ʼִ�С����а���Ϊ��
    β��Ϊ1��6����һ����
    β��Ϊ2��7���ܶ�����
    β��Ϊ3��8����������
    β��Ϊ4��9����������
    β��Ϊ5��0����ĸ����������
    ��֪2000��1��1��Ϊ���������ڸ���һЩ���ںͳ��ƺţ����ʸû������ڸ����Ƿ����С�
��������
    �����һ��Ϊһ������n��1<=n<=100������ʾ���Ե�������
    ֮������n�У�ÿһ����һ�����ں�һ�����ƺ���ɣ��ÿո�ָ������ڵĸ�ʽΪ��YYYY-MM-DD"�����硰2000-01-23�������ڱ�
    ֤��2000��1��1�ա�9999��12��31��֮�䣻���ƺŵĸ�ʽΪ6λ�ַ����������ֺʹ�д��ĸ��ɣ����硰A123Q6����
�������
    �����n�У�����ÿһ��������һ�С���������ĳ����ڸ����������У��������yes�������������no����
��������
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
�������
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
��ʾ
    �뿼�����ꡣ
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
