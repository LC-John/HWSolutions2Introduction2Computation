/*****
����
    ���һ�����������в����������ͬ������֮��
��������
    �����Ϊ���У�
    ��һ��ΪN(NΪ���������ֵĸ�����N<=100)��
    �ڶ���ΪN���������Կո������
�������
    ���ΪN�����г�ȥ�������������֮�͡���ע�⣬��������ܳ��ֶ�Σ�
��������
    3
    1 2 3
�������
    3
*****/

#include <iostream>
using namespace std;

int main ()
{
    int n = 0, num[200] = {0}, max = 0, cnt = -1, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        sum += num[i];
        if (cnt < 0 || num[i] > max)
        {
            max = num[i];
            cnt = 1;
        }
        else if (num[i] == max)
            cnt++;
    }
    cout << sum - max * cnt;
    return 0;
}
