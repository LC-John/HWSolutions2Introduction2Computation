/*****
����
    Ѱ�������ԣ�Ҫ������������֮��ľ���ֵ��������������[m,n]��Χ�ڣ�����m��n�����У�m��n��������
    ������mС��n��Ѱ�������������ԡ������������������������(k1,K2)����������ڣ������ NULL��
�ٶ�n�����ֵ������ 200000
��������
������m �� n���Զ��ż����
�������
    ���[m,n]��Χ�ڵ����������У�ÿһ����������(k1,k2)����ʽ��ʾ��ż��֮���Էֺż�������У�k1С��
    k2��Ҫ��k1��С��ż�����������k1��ȵ�����£�k2��С��ż������������û�У����NULL
��������
    1,15
�������
    (2,5)
    (2,7)
    (2,13)
    (3,5)
    (5,7)
    (11,13)
*****/

#include <iostream>
using namespace std;

#define MAX_N 300000

int prime[MAX_N] = {2, 3, 5, 7}, is_prime[MAX_N] = {0, 0, 1, 1, 0, 1, 0, 1}, n_prime = 4;

int main()
{
    int m = 0, n = 0;
    char c;
    bool output_null = true;
    cin >> m >> c >> n;
    for (int i = 11; i <= n; i += 2)
    {
        bool flag = true;
        for (int j = 0; j < n_prime; j++)
            if (i % prime[j] == 0)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            prime[n_prime++] = i;
            is_prime[i] = 1;
        }
    }
    for (int i = m; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (is_prime[i] && is_prime[j] && is_prime[j - i])
            {
                output_null = false;
                cout << "(" << i << "," << j << ")" << endl;
            }
    if (output_null)
        cout << "NULL";
    return 0;
}
