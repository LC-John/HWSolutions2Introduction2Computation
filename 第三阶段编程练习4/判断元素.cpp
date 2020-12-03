/*****
����
    ��һ������M���������ɵģ�
    (1) ��֪ k �Ǽ��� M ��Ԫ�أ�
    (2) ��� y �� M ��Ԫ�أ���ô�� 2y+1 �� 3y+1 ���� M ��Ԫ�أ�
    (3) ����������������⣬û�б�����ܹ���Ϊ M ��һ��Ԫ�ء�
    ���⣺������� k �� x�����ж� x �Ƿ��� M ��Ԫ�ء������ k���޷���������x ������ 100000��
    ����ǣ������YES��������� NO
��������
    �������� k �� x, ���ż����
�������
    ����ǣ������ YES���������NO
��������
    0,22
�������
    YES
*****/

#include <iostream>
#include <cstring>
using namespace std;

bool check_M(int y, int x, bool *visit)
{
    bool ret = false;
    if (y > x)          // ����������Χ����ֹ
        return false;
    if (y == x)         // ����������ֹ
        return true;
    if (visit[y])       // ���������������ֹ
        return false;
    ret = ret || check_M(2 * y + 1, x, visit);
    visit[2 * y + 1] = true;
    if (ret)
        return true;
    ret = ret || check_M(3 * y + 1, x, visit);
    visit[3 * y + 1] = true;
    return ret;
}

int main()
{
    int k = 0, x = 0;
    bool *visit = NULL;
    char c = '\0';
    cin >> k >> c >> x;
    visit = new bool[x * 4];    // ��̬���������ָ��
    memset(visit, 0, sizeof(bool) * x * 4);
    if (check_M(k, x, visit))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
