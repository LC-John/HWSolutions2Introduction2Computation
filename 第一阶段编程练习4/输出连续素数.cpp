/*****
����
    ��д���򣬽���������m�ҽ���m��k�����������kС��10����
��������
    ����Ϊһ�У�����������������һ��Ϊ����m���ڶ���Ϊ����k
�������
    ���Ϊһ�У�������������k������
��������
    3 4
�������
    5 7 11 13
*****/

#include <iostream>
using namespace std;

#define MAX_N 10000

int prime[MAX_N] = {2, 3, 5, 7}, n_prime = 4;

bool check_prime(int num)
{
    for (int i = 0; i < n_prime && prime[i] < num; i++)
        if (num % prime[i] == 0)
            return false;
    if (prime[n_prime-1] < num)
        prime[n_prime++] = num;
    return true;
}

int main()
{
    int m, k;
    bool whitespace = false;
    cin >> m >> k;
    for (int i = prime[n_prime-1] + 2; i <= m; i += 2)
        check_prime(i);
    for (int i = m + 1; k > 0; i++)
        if (check_prime(i))
        {
            if (whitespace)
                cout << " ";
            else
                whitespace = true;
            cout << i;
            k--;
        }
    return 0;
}
