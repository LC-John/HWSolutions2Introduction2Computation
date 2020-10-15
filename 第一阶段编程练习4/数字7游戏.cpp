/*****
描述
    元旦晚会上，有n个学生围坐成一圈，开始玩一种数字7游戏。围坐成一圈的学生按顺时针顺序编号，第一个学生的编号为1，最后一个学生的编号为n。
    第一个学生从1开始报数，按顺时针方向，下一个学生接着报下一个数。每当有学生报出来的数是7的倍数，或者是一个含有数字7的数时，则该学生出
    列退出游戏，下一个学生接着报下一个数。当剩下最后一个学生时，这个学生要为大家表演一个节目。
关于输入
    输入仅一个整数n（n≤100），学生人数。
关于输出
    按学生退出游戏的顺序输出学生的编号，每行一个编号。
例子输入
    5
例子输出
    2
    5
    4
    3
    1
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000

bool check7(int num)
{
    if (num % 7 == 0)
        return true;
    for (; num > 0; num /= 10)
        if (num % 10 == 7)
            return true;
    return false;
}

int main()
{
    bool stu[MAX_N] = {false};
    int n = 0, num = 0, cnt = 0;
    cin >> n;
    for (int curr = 0; cnt < n; curr = (curr + 1) % n)
    {
        if (stu[curr])
            continue;
        if (check7(++num))
        {
            cout << curr+1 << endl;;
            stu[curr] = true;
            cnt++;
        }
    }
    return 0;
}
