/*****
����
    ѧϰ�˼�����ۿ�֮������֪�������ڼ���������Զ����ƴ洢�ġ���ѧ��ȤС��������о�������������֪����
    �����Ķ����Ʊ�ʾ��ʲô���ɣ����磺�����Ķ����Ʊ�ʾ��1�ĸ����ǲ������������Ǹ������Ʊ�ʾ��1�ĸ�����Ȼ��
    ������������ȡ��Ϊ��˫����������������д��һ������ͳ�Ʋ�����n�����������ж��ٸ���˫��������
��������
    ������У�ÿ��һ����������������n����n<=12345��
�������
    ������У�ÿ��һ������������Ӧ�Ĳ�����n���������С�˫�������ĸ���
��������
    3
�������
    1
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 12355

bool is_prime[MAX_N] = {false};

int cnt1(unsigned int num)
{
    int cnt = 0;
    for (; num > 0; num = num >> 1)
        cnt += num & 1;
    return cnt;
}

int main()
{
    int n = 0, last_n = -1;
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < MAX_N; i++)
        if (is_prime[i])
            for (int j = i + i; j < MAX_N; j += i)
                is_prime[j] = false;
    while (cin >> n)
    {
        int cnt = 0;
        for (int i = 0; i <= n; i++)
            if (is_prime[i] && is_prime[cnt1(i)])
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
