/*****
����
    һ��ʮ������Ȼ��,�����߽�����Ž��Ʊ�ʾ������λ�������߽�����Ž��Ƶ���λ�����ʾ˳�������෴����������Ȼ��,�������ʾ.
    ����Ϊ1ʱ���������Ȼ����ʮ���Ʊ��ʽ������Ϊ2ʱ���������Ȼ�����߽��Ʊ��ʽ������Ϊ3ʱ���������Ȼ���ľŽ��Ʊ��ʽ��
��������
    ����Ϊ1��2��3�е�һ������
�������
    ���һ�С�
    ���Ϊʮ���ƻ��߽��ƻ�Ž�����
��������
    1
�������
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10

int seven[MAX_N] = {0};
int nine[MAX_N] = {0};
int num = 0;


int main()
{
    int num_start = 1 * 9 * 9;
    int num_end = 6 * 7 * 7 + 6 * 7 + 6;
    int choice;
    for (num = num_start; num < num_end; num++)
    {
        memset(seven, 0, sizeof(seven));
        memset(nine, 0, sizeof(nine));
        for (int i = 0, tmp = num; tmp > 0; i++, tmp /= 7)
            seven[i] = tmp % 7;
        for (int i = 0, tmp = num; tmp > 0; i++, tmp /= 9)
            nine[i] = tmp % 9;
        if (seven[0] == nine[2] && seven[1] == nine[1] && seven[2] == nine[0])
            break;
    }
    cin >> choice;
    switch(choice)
    {
    case 1: cout << num; break;
    case 2:
        for (int i = 2; i >= 0; i--)
            cout << seven[i];
        break;
    case 3:
        for (int i = 2; i >= 0; i--)
            cout << nine[i];
        break;
    default: break;
    }
    return 0;
}
