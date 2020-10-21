/*****
描述
    4名专家对4款赛车进行评论
    1）A说：2号赛车是最好的；
    2）B说：4号赛车是最好的；
    3）C说：3号赛车不是最好的；
    4）D说： B说错了。
    事实上只有1款赛车最佳，且只有1名专家说对了，其他3人都说错了。
    请编程输出最佳车的车号，以及说对的专家。
关于输入
    无输入。
关于输出
    输出两行。第一行输出最佳车的车号（1-4中的某个数字）。第二行输出说对的专家（A-D中的某个字母）。
例子输入
例子输出
    1
    A
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000

int main()
{
    bool comment[MAX_N] = {false};
    for (int best = 1; best <= 4; best++)
    {
        char correct;
        int n_correct = 0;
        comment['A'] = best == 2;
        comment['B'] = best == 4;
        comment['C'] = best != 3;
        comment['D'] = !comment['B'];
        for (char i = 'A'; i <= 'D'; i++)
            if (comment[i])
            {
                correct = i;
                n_correct++;
            }
        if (n_correct == 1)
            cout << best << endl << correct << endl;
    }
    return 0;
}
