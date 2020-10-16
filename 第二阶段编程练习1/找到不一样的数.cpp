/*****
描述
    有n个数，在这n个数中，只有一个数字出现了奇数次，其余都出现了偶数次，你能找到出现奇数次的数字么？
关于输入
    输入有两行，第一行一个数n(1<=n<=100000)，表示数的数量，第二行n个整数，表示这n个数字(1<=数字大小<=100)，数据保证只有一个数字出现奇数次。
关于输出
    输出一行，一个数，即出现奇数次的数字。
例子输入
    7
    1 2 1 2 1 3 3
例子输出
    1
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000
#define MIN_NUM 1
#define MAX_NUM 100

// 使用异或运算的方法
// 异或运算的特性是对任意的n和m来说，都有n ^ m ^ m == n
// 因此把所有输入进行异或运算的话，最后只会剩下出现奇数次的那个数
/*
int solution_xor()
{
    int n = 0, num = 0, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (res <= 0)
            res = num;
        else
            res ^= num;
    }
    cout << res;
    return 0;
}
*/

int main()
{
    //solution_xor();
    int cnt[MAX_N] = {0}, n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        cnt[num]++;
    }
    for (int i = MIN_NUM; i <= MAX_NUM; i++)
        if (cnt[i] % 2 == 1)
            cout << i;
    return 0;
}
