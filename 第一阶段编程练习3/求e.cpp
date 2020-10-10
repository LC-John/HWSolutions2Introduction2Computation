/*****
����
    ����n��ֵ, ���㹫ʽ e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + �� + 1/n!
��������
    ֻ��һ�����룬��n��ֵ, n>=1, ��nΪ����
�������
    ����������ʽ�����e��ֵ����ȷ��С�����6λ��
��������
    5
�������
    2.716667
*****/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double e = 1, n = 1;
    cin >> n;
    for (int factorial = 1, base = 1; base <= n; base++)
    {
        factorial *= base;
        e += 1. / factorial;
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << e;
    return 0;
}
