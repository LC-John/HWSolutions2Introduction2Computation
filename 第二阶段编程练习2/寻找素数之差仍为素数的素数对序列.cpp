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

#include <cstdio>
#include <cstring>
#include <cmath>

#define MAX_N 300000

int is_prime[MAX_N] = {0};

void gen_prime(int n)
{
    double sqrt_n = sqrt(n);
    memset(is_prime, -1, sizeof(is_prime));
    is_prime[1] = 0;
    for (int i = 2; i <= sqrt_n; i++)
    {
        if(!is_prime[i])
            continue;
        for (int j = i * 2; j <= n; j += i)
            is_prime[j] = 0;
    }
}

int main()
{
    int m = 0, n = 0;
    bool output_null = true;
    scanf("%d,%d", &m, &n);
    gen_prime(n);
    for (int i = m; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (is_prime[i] && is_prime[j] && is_prime[j - i])
            {
                output_null = false;
                printf("(%d,%d)\n", i, j);
            }
    if (output_null)
        printf("NULL");
    return 0;
}
