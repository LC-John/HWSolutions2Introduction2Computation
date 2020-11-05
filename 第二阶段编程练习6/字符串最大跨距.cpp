/*****
描述
    有三个字符串S,S1,S2，其中，S长度不超过300,S1和S2的长度不超过10，想检测S1和S2是否同时在S中出现，且S1位于S2的左边，
    并在S中互不交叉（即，S1的右边界点在S2的左边界点的左侧）。计算满足上述条件的最大跨距（即，最大间隔距离：最右边的S2
    的起始点与最左边的S1的终止点之间的字符数目）。如果没有满足条件的偶对S1，S2存在，则输出 -1
    例如，S = "abcd123ab888efghij45ef67kl", S1="ab", S2="ef"，其中，S1在S中出现了2次，S2也在S中出现了2次，最大跨距
    则为：18
关于输入
    三个串：S, S2, S3，其间以逗号间隔（注意，S, S2, S3中均不含逗号）；
关于输出
    S1和S2在S最大跨距；若在S中没有满足条件的S1和S2，则输出-1
例子输入
    abcd123ab888efghij45ef67kl,ab,ef
例子输出
    18
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 500

int main()
{
    char s[MAX_LEN] = "\0", *s1 = NULL, *s2 = NULL;
    int l = 0, l1 = 0, l2 = 0, flag = 0, _st = 0, _end = 0, idx = 0;
    cin.getline(s, MAX_LEN);
    for (int i = 0; s[i] != '\0'; i++)
        if (flag == 0 && s[i] == ',')
        {
            flag++;
            s[i] = '\0';
            s1 = s + i + 1;
        }
        else if (s[i] == ',')
        {
            s[i] = '\0';
            s2 = s + i + 1;
            break;
        }
    l = strlen(s);
    l1 = strlen(s1);
    l2 = strlen(s2);
    // cout << s << endl << s1 << endl << s2 << endl;
    // 从左向右找S1的匹配
    for (idx = 0, _st = 0; _st < l; _st++)
        if (s1[idx] == '\0')
            break;
        else if (s1[idx] == s[_st])
            idx++;
    if (idx < l1)
    {
        cout << -1;
        return 0;
    }
    // 从右向左找S2的匹配
    for (idx = l2 - 1, _end = l - 1; _end >= 0; _end--)
        if (idx < 0)
            break;
        else if (s2[idx] == s[_end])
            idx--;
    if (idx >= 0 || _st > _end + 1)
    {
        cout << -1;
        return 0;
    }
    // cout << _st << " " << _end << endl;
    cout << _end - _st + 1;
    return 0;
}
