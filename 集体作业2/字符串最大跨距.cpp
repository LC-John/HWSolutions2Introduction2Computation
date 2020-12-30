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

int find_match(char* s, char* _s, int l, int _l)
{
    for (int i = 0; i < l - _l; i++)
    {
        bool flag = true;
        for (int j = 0; j < _l && i + j < l; j++)
            if (s[i + j] != _s[j])
            {
                flag = false;
                break;
            }
        if (flag)
            return i + _l;
    }
    return -1;
}

char* str_reverse(char* str, int len)   // ��ת�ַ���
{
    int i = len / 2;
    if (len % 2 == 1)
        i++;
    for (; i < len; i++)
    {
        str[i] = str[i] ^ str[len-1-i];
        str[len-1-i] = str[i] ^ str[len-1-i];
        str[i] = str[i] ^ str[len-1-i];
    }
    return str;
}

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
    _st = find_match(s, s1, l, l1);
    if (_st < 0)
    {
        cout << -1;
        return 0;
    }
    // ����������S2��ƥ��
    str_reverse(s, l);      // ��s��s2��ת
    str_reverse(s2, l2);
    _end = find_match(s, s2, l, l2);    // ��������find_match����
    if (_end < 0 || _st > l - _end)
    {
        cout << -1;
        return 0;
    }
    _end = l - 1 - _end;    // ����_end���ڷ�ת���ַ������ҵ���ƥ�䣬�����Ҫ��ת_end
    // cout << _st << " " << _end << endl;
    cout << _end - _st + 1;
    return 0;
}
