/*****
����
    ��һ��С�͵ı���ϵͳ���������¹��ܣ�
    ��1��ͳ��ÿ����������Ʊ����Ǯ��
    ��2��ͳ��ÿ�෢Ʊ����Ǯ��
    ����ϵͳ��Ϊ���£����跢Ʊ�����A��B��C����;һ���������ˣ�ID�ֱ�Ϊ1��2��3��
��������
    ϵͳ����������У�ÿ�е�һ����Ϊ��ԱID�����ͣ�1��2��3�����ڶ�����Ϊ��Ʊ������(����������100)��֮���Ƕ����Ʊ����ַ�
    �ͣ�A��B��C������Ӧ��Ʊ�������ȸ�����,������1000.0����
�������
    ����������У�ǰ����Ϊÿ�ˣ���ID��С���������������Ʊ��Ǯ����������λС������������Ϊÿ�෢Ʊ����Ǯ����������λС������
��������
    1 5 A 1.0 A 2.0 C 1.0 B 1.0 C 1
    3 3 B 1 C 2  C 1
    2 4 B 1  A 1 C 1 A 1
�������
    1 6.00
    2 4.00
    3 4.00
    A 5.00
    B 3.00
    C 6.00
*****/

#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_N 3

int main()
{
    double ids[MAX_N] = {0}, types[MAX_N] = {0};
    for (int line = 0; line < MAX_N; line++)
    {
        char ch = '\0';
        int n = 0, id = 0, type = 0;
        double exp = 0;
        cin >> ch >> n;
        id = ch - '1';
        for (int i = 0; i < n; i++)
        {
            cin >> ch >> exp;
            type = ch - 'A';
            ids[id] += exp;
            types[type] += exp;
        }
    }
    for (int i = 0; i < MAX_N; i++)
        cout << char('1'+i) << " " << setiosflags(ios::fixed) << setprecision(2) << ids[i] << endl;
    for (int i = 0; i < MAX_N; i++)
        cout << char('A'+i) << " " << setiosflags(ios::fixed) << setprecision(2) << types[i] << endl;
    return 0;
}
