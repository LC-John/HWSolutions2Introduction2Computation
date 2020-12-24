/*****
描述
    在数字信号处理中，卷积是一种重要的运算。通常，我们使用快速傅立叶变换(FFT)来计算卷积。这里，为了编程简单起见，
    我们直接在时域计算卷积。设a,b是长度分别为M和N的数字信号，则a与b的卷积定义为，i=0, 1, …, M+N-2。结果得到一个
    长度为M+N-1的数字信号。
    关于数字信号的说明：本题中，对于一个长度为M的数字信号，其在 ｛0，1，……，M-1｝ 之外的取值均为0
关于输入
    第一行是一个正整数，表示测试数据的组数。
    从第二行开始，每两行表示一组测试数据：例如，第二行有两个正整数M和N(都不大于30)，分别表示两个数字信号的长度；
    第三行是M+N个整数，前M个数表示第一个信号的取值，后N个数表示第二个信号的取值。
关于输出
    对于每组测试数据，输出一行整数，即本组两个输入信号的卷积结果
例子输入
    2
    4 3
    2 1 4 1 3 1 5
    10 10
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
例子输出
    6 5 23 12 21 5
    11 34 70 120 185 266 364 480 615 770 804 816 805 770 710 624 511 370 200
提示
    采用数组来存储数字信号
*****/

#include <iostream>

using namespace std;

int main()
{
    int n_case = 0;
    cin >> n_case;
    while (n_case--)
    {
        int m, n;
        cin >> m >> n;
        int *p = new int[m];
        int *q = new int[n];
        for (int i = 0; i < m; i++)
            cin >> p[i];
        for (int i = 0; i < n; i++)
            cin >> q[i];
        for (int i = 0; i <= m + n - 2; i++)
        {
            int j;
            int convolution = 0;
            if (i >= n)
                j = i - n + 1;
            else if (i < n)
                j = 0;
            for (j; j <= m - 1 && i - j >= 0; j++)
                convolution += p[j] * q[i - j];
            if (i < m + n - 2)
                cout << convolution << " ";
            else
                cout << convolution << endl;
        }
        delete[] p;
        delete[] q;
    }
    return 0;
}
