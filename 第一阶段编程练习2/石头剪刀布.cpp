/*****
����
    ʯͷ���Ӳ���һ�ֺܼ򵥵���Ϸ��
    ʯͷʤ����
    ����ʤ��
    ��ʤʯͷ
    A��B��ȭ����֪���ǳ�ȭ�����У�������˭ʤ˭����
��������
    ��һ����һ��������n(n<200)������A��Bһ������n��ȭ��
    ��������n�У�ÿ�����������֣��ֱ��ʾA��B����β�ȭ�г���ʲô��0��ʾʯͷ��1��ʾ������2��ʾ����
�������
    ���һ�У�"A"��ʾAʤ��"B"��ʾBʤ��"Tie"��ʾƽ�֡�
��������
    4
    1 0
    2 2
    1 2
    2 0
�������
    A
*****/

#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0, w = 0, n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        switch((a - b + 3) % 3)
        {
        case 1: w--; break; // BӮ
        case 2: w++; break; // AӮ
        case 0:              // ƽ��
        default: break;
        }
    }
    if (w > 0)
        cout << "A";
    else if (w < 0)
        cout << "B";
    else
        cout << "Tie";
    return 0;
}
