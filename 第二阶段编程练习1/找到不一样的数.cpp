/*****
����
    ��n����������n�����У�ֻ��һ�����ֳ����������Σ����඼������ż���Σ������ҵ����������ε�����ô��
��������
    ���������У���һ��һ����n(1<=n<=100000)����ʾ�����������ڶ���n����������ʾ��n������(1<=���ִ�С<=100)�����ݱ�ֻ֤��һ�����ֳ��������Ρ�
�������
    ���һ�У�һ�����������������ε����֡�
��������
    7
    1 2 1 2 1 3 3
�������
    1
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000
#define MIN_NUM 1
#define MAX_NUM 100

// ʹ���������ķ���
// �������������Ƕ������n��m��˵������n ^ m ^ m == n
// ��˰�������������������Ļ������ֻ��ʣ�³��������ε��Ǹ���
/*
int solution_xor()
{
    int n = 0, num = 0, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (res <= 0)
            res = num;
        else
            res ^= num;
    }
    cout << res;
    return 0;
}
*/

int main()
{
    //solution_xor();
    int cnt[MAX_N] = {0}, n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        cnt[num]++;
    }
    for (int i = MIN_NUM; i <= MAX_NUM; i++)
        if (cnt[i] % 2 == 1)
            cout << i;
    return 0;
}
