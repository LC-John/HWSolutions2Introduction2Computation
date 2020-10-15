# 第一阶段编程练习2

本次作业主要在于练习循环和比较，此外对于最基础的找最大最小数等算法也进行了练习。总的来说，熟悉了语法后题目难度都不算大。

## 不与最大数相同的数字之和

该题目比较简单，只需要扫描一遍数组即可，在扫描的过程中需要找到最大的数并对其出现的次数计数，此外还需要计算整个数组的值之和。完成扫描后直接相减即可得到答案。

```cpp
#include <iostream>
using namespace std;

int main ()
{
    // num用来存放数组，但其实没有必要
    // max用来记录最大数的值，cnt用来记录对应的max出现的次数
    // sum用来记录数组中元素的和
    int n = 0, num[200] = {0}, max = 0, cnt = -1, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];  // 读入数字
        sum += num[i];  // 求和
        if (cnt < 0 || num[i] > max)    // cnt < 0表明刚读了第一个数，因此需要将其赋值给max
        {                               // num[i] > max表明出现了比当前max还大的数
            max = num[i];               // 更新max为当前数num[i]
            cnt = 1;                    // 更新cnt为1 (max出现了一次)
        }
        else if (num[i] == max)         // 若num[i] == max，说明max又出现了
            cnt++;                      // 更新cnt，加一
    }
    cout << sum - max * cnt;            // 相减得到不与最大数相同的数字之和
    return 0;
}
```

## 人民币支付

该题目使用贪心法即可，使用可用的最大面值的钞票就可以。需要注意的是，没有必要一次一次减，我们可以灵活使用整型除法的特点直接计算。此外，题目要求使用数组和循环完成，不要使用若干个if判断。

```cpp
#include <iostream>
using namespace std;

#define MAX_N 100

int main()
{
    int val[MAX_N] = {1, 5, 10, 20, 50, 100}, n_val = 6, price = 0;
    cin >> price;
    for (int i = n_val-1; i >= 0; i--)
    {
        cout << price / val[i] << endl;
        price %= val[i];
    }
    return 0;
}
```

## 最大最小数之差

题目需要求取三数中最大和最小的数。下面的代码是最简单的方法，直接使用a、b和c三个变量完成，为了交换值，还额外使用了另一个变量d。

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c;
    if (a < b)
    {
        d = a;
        a = b;
        b = d;
    }
    if (a < c)
    {
        d = a;
        a = c;
        c = d;
    }
    if (b < c)
    {
        d = b;
        b = c;
        c = d;
    }
    cout << a - c;
    return 0;
}
```

额外提一下，交换两个变量的值，可以使用位运算中的异或运算，从而不使用额外的变量。

```cpp
int a = 10, b = 5;  // a = (1010), b = (0101)，二进制表示
a = a ^ b;          // a = (1111), b = (0101)
b = a ^ b;          // a = (1111), b = (1010)，a原本的值已经交换给了b
a = a ^ b;          // a = (0101)，b = (1010)，b原本的值也交换给了a
```

最后，除了这种简单的方法，也可以通过数组排序完成本题目。排序算法在输出前k大的数题目里讲解，此题略过。

## 石头剪刀布

该题目基本没有难点，比较复杂的可能是对于胜负的判断。只要能简单地判断出A和B每一局谁赢了，就可以非常方便地进行计分并完成题目。

```cpp
#include <iostream>
using namespace std;

int main()
{
    // 不需要使用数组，用w的正负来计分即可
    int a = 0, b = 0, w = 0, n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        // 使用(a - b + 3) % 3来判断A和B的输赢
        switch((a - b + 3) % 3)
        {
        case 1: w--; break; // 为1的情况下，(A, B)为(剪刀, 石头)或(布, 剪刀)或(石头, 布)，均为B获胜
        case 2: w++; break; // 为2的情况下，(A, B)为(石头, 剪刀)或(剪刀, 布)或(布, 石头)，均为A获胜
        case 0:             // 为0的情况下，A和B相同，均为平局
        default: break;
        }
    }
    if (w > 0)      // w > 0表示目前A获胜
        cout << "A";
    else if (w < 0) // w < 0表示目前B获胜
        cout << "B";
    else            // w == 0表示目前平局
        cout << "Tie";
    return 0;
}
```

## 跳绳统计

该题目迷惑性较强，一定注意审题。输入的是跳了多少个而不是过去了多少秒，因此需要在程序里计数，并分辨跳坏时过去的秒数与跳坏时共跳了几个。

```cpp
#include <iostream>
using namespace std;

#define MAX_N 200

int main()
{
    // sec数组记录一分钟内每一秒是否有跳绳，0表示跳了，1表示没有
    // cnt记录一分钟内没有跳绳的秒数
    int sec[MAX_N] = {0}, n = 0, curr = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> curr;    // 当前跳坏时共跳了多少个
        int _cnt = 0;
        for (int j = curr+cnt;          // curr+cnt为跳坏时的真实秒数
             j < 60 && j < curr+cnt+3;  // 考虑一分钟内跳坏后的三秒
             j++)
            if (sec[j] <= 0)    // 避免重复计数
            {
                sec[j] = 1;     // 记录没有跳绳
                _cnt += 1;
            }
        cnt += _cnt;
    }
    cnt = 60;   // 用60减去sec中所有没有跳绳的秒即可
    for (int i = 0; i < 60; i++)
        cnt -= sec[i];
    cout << cnt;
    return 0;
}
```

## 输出前k大的数

该题目的思路比较明确，需要对数组排序，然后从大往小输出k个数即可。因此所有难点都在排序算法上，如下解法是简单排序算法中的一种。

```cpp
#include <iostream>
//#include <algorithm>
using namespace std;

#define MAX_N 1010

int main()
{
    int num[MAX_N] = {0}, n = 0, k = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    cin >> k;
    // 可以直接使用库函数sort排序，但在没有掌握算法时不建议直接调库
    // sort(num, num+n);
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (num[i] > num[j])
            {
                num[i] = num[i] ^ num[j];   // 三次异或交换数值
                num[j] = num[i] ^ num[j];
                num[i] = num[i] ^ num[j];
            }
    for (int i = n-1; i >= n-k; i--)
        cout << num[i] << endl;
    return 0;
}
```