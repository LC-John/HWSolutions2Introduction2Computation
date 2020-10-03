/*****
描述
    北医三院近期开展了最受欢迎的医生评选活动，评选规则是：请患者及其家属给自己最喜欢的医生投票（每位参加评选的医生有一个相应的编号），票数最多的医生评选为年度最受欢迎医生，奖励年终休假一个月。
关于输入
    输入为两行，第一行为投票的总数n（0 < n <= 100），第二行为投票情况（医生编号均为整数,最大不超过15）
关于输出
    输出最受欢迎的医生的编号
例子输入
    8
    1 3 4 1 1 7 2 2
例子输出
    1
提示
    1.票数最多的医生是唯一的，即不会出现多个医生的票数都是最多的情况
    2.医生的编号最大不超过15
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

int main()
{
    int doc[MAX_N] = {0}, n = 0, vote = 0, idx = 0, max_vote = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> vote;
        doc[vote]++;
        if (doc[vote] > max_vote)
        {
            max_vote = doc[vote];
            idx = vote;
        }
    }
    cout << idx;
    return 0;
}
