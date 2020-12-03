/*****
����
    ��һ������1���������ֽ�Ϊ�������Ļ�
��������
    һ������1�����������磬72
�������
    �ֽ�Ϊ�������Ļ����������
    72=2*2*2*3*3
��������
    72
�������
    72=2*2*2*3*3
*****/

#include <cstdio>
#include <cstring>

#define MAX_N 1000000

bool is_prime[MAX_N] = {false}; // ɸ��

int main()
{
    int num = 0;
    bool flag = true;
    scanf("%d", &num);
    printf("%d=", num);
    memset(is_prime+2, 0xff, sizeof(bool)*(MAX_N-2));
    for (int i = 2; i <= num; i++)
        if (is_prime[i])    // ��������
        {
            for (int j = i + i; j <= num; j += i)
                is_prime[j] = false;
            while (num % i == 0)    // ���õ�ǰ�����ֽ�
            {
                num /= i;
                if (flag)
                    flag = false;
                else
                    printf("*");
                printf("%d", i);
            }
        }
    return 0;
}
