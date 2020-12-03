/*****
描述
    任意给定两个正整数，如果这两个数的质因数均相同，那么这两个数称为密切数。例如 6 和 12，
    其质因数均是 2 和 3；因此，6 和 12 是一对密切数。请判断任意给定的两个正整数是否为一对
    密切数。若是，输出YES，若不是，输出NO 。
关于输入
    输入两个正整数，用逗号间隔
关于输出
    若是密切数，输出YES；
    若不是，输出NO；
例子输入
    18,12
例子输出
    YES
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000000

bool is_prime[MAX_N] = {false};

int main()
{
    int x = 0, y = 0;
    char c = '\0';
    cin >> x >> c >> y;
    if (x > y)
    {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
    memset(is_prime + 2, true, sizeof(bool) * (MAX_N - 2));
    for (int i = 2; i < y; i++)
        if (is_prime[i])
        {
            for (int j = i + i; j < y; j += i)
                is_prime[j] = false;
            if ((!(x % i) && (y % i)) || ((x % i) && !(y % i)))
            {
                cout << "NO";
                return 1;
            }
        }
    cout << "YES";
    return 0;
}
