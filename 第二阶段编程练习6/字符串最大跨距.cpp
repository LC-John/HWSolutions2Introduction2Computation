/*****
����
    �������ַ���S,S1,S2�����У�S���Ȳ�����300,S1��S2�ĳ��Ȳ�����10������S1��S2�Ƿ�ͬʱ��S�г��֣���S1λ��S2����ߣ�
    ����S�л������棨����S1���ұ߽����S2����߽�����ࣩ������������������������ࣨ������������룺���ұߵ�S2
    ����ʼ��������ߵ�S1����ֹ��֮����ַ���Ŀ�������û������������ż��S1��S2���ڣ������ -1
    ���磬S = "abcd123ab888efghij45ef67kl", S1="ab", S2="ef"�����У�S1��S�г�����2�Σ�S2Ҳ��S�г�����2�Σ������
    ��Ϊ��18
��������
    ��������S, S2, S3������Զ��ż����ע�⣬S, S2, S3�о��������ţ���
�������
    S1��S2��S����ࣻ����S��û������������S1��S2�������-1
��������
    abcd123ab888efghij45ef67kl,ab,ef
�������
    18
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 500

int main()
{
    char s[MAX_LEN] = "\0", *s1 = NULL, *s2 = NULL;
    int l = 0, l1 = 0, l2 = 0, flag = 0, _st = 0, _end = 0, idx = 0;
    cin.getline(s, MAX_LEN);
    for (int i = 0; s[i] != '\0'; i++)
        if (flag == 0 && s[i] == ',')
        {
            flag++;
            s[i] = '\0';
            s1 = s + i + 1;
        }
        else if (s[i] == ',')
        {
            s[i] = '\0';
            s2 = s + i + 1;
            break;
        }
    l = strlen(s);
    l1 = strlen(s1);
    l2 = strlen(s2);
    // cout << s << endl << s1 << endl << s2 << endl;
    // ����������S1��ƥ��
    for (idx = 0, _st = 0; _st < l; _st++)
        if (s1[idx] == '\0')
            break;
        else if (s1[idx] == s[_st])
            idx++;
    if (idx < l1)
    {
        cout << -1;
        return 0;
    }
    // ����������S2��ƥ��
    for (idx = l2 - 1, _end = l - 1; _end >= 0; _end--)
        if (idx < 0)
            break;
        else if (s2[idx] == s[_end])
            idx--;
    if (idx >= 0 || _st > _end + 1)
    {
        cout << -1;
        return 0;
    }
    // cout << _st << " " << _end << endl;
    cout << _end - _st + 1;
    return 0;
}
