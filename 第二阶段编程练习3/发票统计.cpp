/*****
描述
    有一个小型的报账系统，它有如下功能：
    （1）统计每个人所报发票的总钱数
    （2）统计每类发票的总钱数
    将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。
关于输入
    系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，之后是多个发票类别（字符
    型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。
关于输出
    输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后三行为每类发票的总钱数（保留两位小数）。
例子输入
    1 5 A 1.0 A 2.0 C 1.0 B 1.0 C 1
    3 3 B 1 C 2  C 1
    2 4 B 1  A 1 C 1 A 1
例子输出
    1 6.00
    2 4.00
    3 4.00
    A 5.00
    B 3.00
    C 6.00
*****/

#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_N 3

int main()
{
    double ids[MAX_N] = {0}, types[MAX_N] = {0};
    for (int line = 0; line < MAX_N; line++)
    {
        char ch = '\0';
        int n = 0, id = 0, type = 0;
        double exp = 0;
        cin >> ch >> n;
        id = ch - '1';
        for (int i = 0; i < n; i++)
        {
            cin >> ch >> exp;
            type = ch - 'A';
            ids[id] += exp;
            types[type] += exp;
        }
    }
    for (int i = 0; i < MAX_N; i++)
        cout << char('1'+i) << " " << setiosflags(ios::fixed) << setprecision(2) << ids[i] << endl;
    for (int i = 0; i < MAX_N; i++)
        cout << char('A'+i) << " " << setiosflags(ios::fixed) << setprecision(2) << types[i] << endl;
    return 0;
}
