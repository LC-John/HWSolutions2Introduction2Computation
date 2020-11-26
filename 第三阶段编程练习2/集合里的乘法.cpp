/*****
����
    ������������S��һ��Ŀ����T���ж��Ƿ���Դ�S����ѡһ���ǿ��Ӽ����Ӽ��е�����˵ĳ˻�ΪT��
��������
    ����Ϊ���С�
    ��һ��ΪĿ����T��S�е�Ԫ�ظ���N���Կո������
    �ڶ���ΪS�е�N��Ԫ�أ��Կո������
    ���� N <= 16��
�������
    ������ԣ������YES���������NO��
��������
    Sample Input 1:
    12 5
    1 2 3 4 5
    Sample Input 2:
    33 5
    4 2 8 7 5
�������
    Sample Output 1:
    YES
    Sample Output 2:
    NO
*****/

#include <iostream>
using namespace std;

#define MAX_N 20

long long num[MAX_N] = {0}, n = 0, goal = 0;

bool func(int idx, long long mul)
{
    if (idx >= n)       // ������Χ
        return false;
    if (mul == goal)    // �ҵ����еķ���
        return true;
    if (func(idx + 1, mul * num[idx]))  // mul�����ϵ�idx�����ķ���
        return true;
    return func(idx + 1, mul);  // mul�ﲻ���idx�����ķ���
}

int main()
{
    cin >> goal >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    if (func(0, 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
