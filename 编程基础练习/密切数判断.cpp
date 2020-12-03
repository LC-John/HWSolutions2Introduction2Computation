/*****
����
    ������������������������������������������ͬ����ô����������Ϊ������������ 6 �� 12��
    ������������ 2 �� 3����ˣ�6 �� 12 ��һ�������������ж���������������������Ƿ�Ϊһ��
    �����������ǣ����YES�������ǣ����NO ��
��������
    �����������������ö��ż��
�������
    ���������������YES��
    �����ǣ����NO��
��������
    18,12
�������
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
