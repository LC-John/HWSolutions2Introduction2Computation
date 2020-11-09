/*****
����
    �������Ǻ��ᣨDNA�������������ļ������˫�����ķ�ʽ��϶��ɡ�������DNA�ļ������4�֣��ֱ�Ϊ����ʣ�A����
    �����ʣ�G����������ण�T���Ͱ���ण�C��������֪��������������������Ķ�Ӧλ���ϣ���������Ǻ����������
    �ԣ����������ǺͰ������ԡ����������Ǹ���һ�������ϵļ�����У�������Ӧ�Ļ������ϵļ�����С�
��������
    ��һ����һ��������n����������n��Ҫ���ļ������
    ���¹���n�У�ÿ����һ���ַ�����ʾһ�������������ַ���ֻ���д�д��ĸA��T��G��C���ֱ��ʾ����ʡ�������
    ड������ʺͰ���ड�ÿ��������ĳ��ȶ�������255��
�������
    ����n�У�ÿ��Ϊһ��ֻ���д�д��ĸA��T��G��C���ַ������ֱ�Ϊ������ĸ�����������ļ������
��������
    5
    ATATGGATGGTGTTTGGCTCTG
    TCTCCGGTTGATT
    ATATCTTGCGCTCTTGATTCGCATATTCT
    GCGTTTCGTTGCAA
    TTAACGCACAACCTAGACTT
�������
    TATACCTACCACAAACCGAGAC
    AGAGGCCAACTAA
    TATAGAACGCGAGAACTAAGCGTATAAGA
    CGCAAAGCAACGTT
    AATTGCGTGTTGGATCTGAA
��ʾ
    ��ע�⣺����n��ȡֵ��Χδ֪���������ڶ���һ�У�����һ�С���Ҫ�������е����ݺ��ٴ���
*****/

#include <iostream>
using namespace std;

#define MAX_LEN 10000

char dna[MAX_LEN] = "\0", match['Z'+1] = "\0";

int main()
{
    int n = 0;
    cin >> n;
    match['A'] = 'T';
    match['T'] = 'A';
    match['C'] = 'G';
    match['G'] = 'C';
    for (int _case = 0; _case < n; _case++)
    {
        cin >> dna;
        for (int i = 0; dna[i] != '\0'; i++)
            cout << match[dna[i]];
        cout << endl;
    }
    return 0;
}
