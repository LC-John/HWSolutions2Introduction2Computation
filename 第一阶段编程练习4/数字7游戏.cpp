/*****
����
    Ԫ������ϣ���n��ѧ��Χ����һȦ����ʼ��һ������7��Ϸ��Χ����һȦ��ѧ����˳ʱ��˳���ţ���һ��ѧ���ı��Ϊ1�����һ��ѧ���ı��Ϊn��
    ��һ��ѧ����1��ʼ��������˳ʱ�뷽����һ��ѧ�����ű���һ������ÿ����ѧ��������������7�ı�����������һ����������7����ʱ�����ѧ����
    ���˳���Ϸ����һ��ѧ�����ű���һ��������ʣ�����һ��ѧ��ʱ�����ѧ��ҪΪ��ұ���һ����Ŀ��
��������
    �����һ������n��n��100����ѧ��������
�������
    ��ѧ���˳���Ϸ��˳�����ѧ���ı�ţ�ÿ��һ����š�
��������
    5
�������
    2
    5
    4
    3
    1
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000

bool check7(int num)
{
    if (num % 7 == 0)
        return true;
    for (; num > 0; num /= 10)
        if (num % 10 == 7)
            return true;
    return false;
}

int main()
{
    bool stu[MAX_N] = {false};
    int n = 0, num = 0, cnt = 0;
    cin >> n;
    for (int curr = 0; cnt < n; curr = (curr + 1) % n)
    {
        if (stu[curr])
            continue;
        if (check7(++num))
        {
            cout << curr+1 << endl;;
            stu[curr] = true;
            cnt++;
        }
    }
    return 0;
}
