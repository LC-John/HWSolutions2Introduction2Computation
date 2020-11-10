/*****
描述
    所谓最简真分数是指分子小于分母，且不能约分的分数。给定 n（1 < n < 200）个非负整数（每个整数不超过3位），
    哪两个整数分别作为分子和分母能够构成最简真分数。输出所有的最简真分数组合；若没有，则输出NO。
关于输入
    第1行为正整数个数n
    其后为n个非负整数，空格间隔。
关于输出
    输出所有最简真分数，分子小的排在前面；若分子相同，分母小的排在前面。各分数之间用逗号间隔。
    若没有，则输出NO
例子输入
    8
    3 7 11 0 5 13 15 9
例子输出
    3/5,3/7,3/11,3/13,5/7,5/9,5/11,5/13,7/9,7/11,7/13,7/15,9/11,9/13,11/13,11/15,13/15
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000

int num[MAX_N] = {0}, n = 0;

int main()
{
    bool first_output = true;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);         // 直接排序，也可以冒泡
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            {
                bool flag = true;
                if (num[i] == 0 || num[j] == 0)     // 不是真分数
                    continue;
                for (int f = 2;f <= num[i]; f++)    // 检查公因数
                    if (num[i] % f == 0 && num[j] % f == 0)
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                {
                    if (!first_output)
                        cout << ",";
                    cout << num[i] << "/" << num[j];
                    first_output = false;
                }
            }
    if (first_output)
        cout << "NO";
    return 0;
}
