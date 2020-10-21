/*****
����
    4��ר�Ҷ�4��������������
    1��A˵��2����������õģ�
    2��B˵��4����������õģ�
    3��C˵��3������������õģ�
    4��D˵�� B˵���ˡ�
    ��ʵ��ֻ��1��������ѣ���ֻ��1��ר��˵���ˣ�����3�˶�˵���ˡ�
    ���������ѳ��ĳ��ţ��Լ�˵�Ե�ר�ҡ�
��������
    �����롣
�������
    ������С���һ�������ѳ��ĳ��ţ�1-4�е�ĳ�����֣����ڶ������˵�Ե�ר�ң�A-D�е�ĳ����ĸ����
��������
�������
    1
    A
*****/

#include <iostream>
using namespace std;

#define MAX_N 1000

int main()
{
    bool comment[MAX_N] = {false};
    for (int best = 1; best <= 4; best++)
    {
        char correct;
        int n_correct = 0;
        comment['A'] = best == 2;
        comment['B'] = best == 4;
        comment['C'] = best != 3;
        comment['D'] = !comment['B'];
        for (char i = 'A'; i <= 'D'; i++)
            if (comment[i])
            {
                correct = i;
                n_correct++;
            }
        if (n_correct == 1)
            cout << best << endl << correct << endl;
    }
    return 0;
}
