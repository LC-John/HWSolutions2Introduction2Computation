/*****
����
    ��̣�����һ���ַ�����������ַ����Ƿ���ġ�
    ��������
����Ϊһ���ַ������ַ�����û�пհ��ַ����ַ������Ȳ�����100����
�������
    ����ַ����ǻ��ģ����yes���������no��
��������
    abcdedcba
�������
    yes
��ʾ
    ������ָ˳���͵�����һ�����ַ�����
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000

bool check(char* str)
{
    char rev_str[MAX_N] = "\0";
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
        rev_str[len - 1 - i] = str[i];
    for (int i = 0; i < len; i++)
        if (str[i] != rev_str[i])
            return false;
    return true;
    // ֱ��ʹ��strcmp�����Ƚ������ַ���
    //return strcmp(str, rev_str) == 0;
}


int main()
{
    char str[MAX_N] = "\0";
    cin >> str;
    if (check(str))
        cout << "yes";
    else
        cout << "no";
    return 0;
}
