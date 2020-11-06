/*****
����
    ���������������ϣ�������������ʱ����Ԫ�ش�С�����˳��������Զ��ż����
    ע�⣺�����ļ����п������ظ�Ԫ�أ�������Ľ����в������ظ�Ԫ�ء����û�н���������� NULL
    ����
    ����A��1,3,5,6,10,6,8,11
    ����B: 2,4,8,6,10,6,12,13
    ��ô�����Ϊ��
    6,8,10
��������
    2�У�ÿ�б�ʾһ�����ϵ�Ԫ�����У�Ԫ��֮���Զ��ż�����ٶ�ÿ�����ϲ�����200��Ԫ�ء�
�������
    �������ϵĽ�������Ԫ�ش�С����������Զ��ż�������û�н���������� NULL
��������
    1,3,5,6,10,6,8,11
    2,4,8,6,10,6,12,13
�������
    6,8,10
��ʾ
    ������Ԫ�صĸ������Լ���취ȷ��
*****/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000

int A[MAX_N] = {0}, B[MAX_N] = {0};
int na = 0, nb = 0;

int main()
{
    bool flag = false;
    int last = 0xffffffff;
    do
        cin >> A[na++];
    while(cin.get() != '\n');
    do
        cin >> B[nb++];
    while(cin.get() != '\n');
    sort(A, A + na);
    sort(B, B + nb);
    for (int i = 0, j = 0; i < na && j < nb;)
        if (A[i] == B[j])
        {
            if (A[i] == last)
            {
                i++;
                j++;
                continue;
            }
            if (flag)
                cout << ",";
            cout << A[i];
            last = A[i];
            i++;
            j++;
            flag = true;
        }
        else if (A[i] < B[j])
            i++;
        else
            j++;
    if (!flag)
        cout << "NULL";
    return 0;
}
