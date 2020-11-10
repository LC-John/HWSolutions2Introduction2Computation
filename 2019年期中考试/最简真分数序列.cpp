/*****
����
    ��ν����������ָ����С�ڷ�ĸ���Ҳ���Լ�ֵķ��������� n��1 < n < 200�����Ǹ�������ÿ������������3λ����
    �����������ֱ���Ϊ���Ӻͷ�ĸ�ܹ���������������������е�����������ϣ���û�У������NO��
��������
    ��1��Ϊ����������n
    ���Ϊn���Ǹ��������ո�����
�������
    ���������������������С������ǰ�棻��������ͬ����ĸС������ǰ�档������֮���ö��ż����
    ��û�У������NO
��������
    8
    3 7 11 0 5 13 15 9
�������
    3/5,3/7,3/11,3/13,5/7,5/9,5/11,5/13,7/9,7/11,7/13,7/15,9/11,9/13,11/13,11/15,13/15
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000

int num[MAX_N] = {0}, n = 0;

int main()
{
    bool first_output = true;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);         // ֱ������Ҳ����ð��
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            {
                bool flag = true;
                if (num[i] == 0 || num[j] == 0)     // ���������
                    continue;
                for (int f = 2;f <= num[i]; f++)    // ��鹫����
                    if (num[i] % f == 0 && num[j] % f == 0)
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                {
                    if (!first_output)
                        cout << ",";
                    cout << num[i] << "/" << num[j];
                    first_output = false;
                }
            }
    if (first_output)
        cout << "NO";
    return 0;
}
