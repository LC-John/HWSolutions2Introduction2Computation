/*****
描述
    一个正整数，如果它能被3整除，或者它的十进制表示法中某个位数上的数字为3，则称其为与3相关的数。现给定一个正整数n(n<100),判断n是否是与3相关的数。
关于输入
    输入为一行，正整数n,n<100
关于输出
    输出为一行，如果n为与3相关的数，则输出TRUE，否则输出FALSE
例子输入
    3
    10
    31
例子输出
    TRUE
    FALSE
    TRUE
*****/

#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        bool flag = true;
        if (num % 3 == 0)
        {
            cout << "TRUE" << endl;
            continue;
        }
        for (int i = num; i > 0; i /= 10)
            if (i % 10 == 3)
            {
                cout << "TRUE" << endl;
                flag = false;
                break;
            }
        if (flag)
            cout << "FALSE" << endl;
    }
    return 0;
}
