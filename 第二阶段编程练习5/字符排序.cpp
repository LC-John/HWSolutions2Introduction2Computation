/*****
����
    ��д���򣬶Ը������ַ��������µ������������򣬲���������Ľ����
    ���������ַ����м�һ��Ϊ������߲��ְ��ַ���ASCIIֵ���������ұ߲��ֱ��ֲ���,Ȼ����߲������ұ�
    ���ֽ��н��������ԭ�ַ�������Ϊ�����������м���ַ����μӴ����ַ��Է���ԭλ���ϡ�
��������
    ����Ϊһ���ַ���
�������
    ���Ϊ��Ҫ�������Ľ��
��������
    abcdhgfe
�������
    hgfedcba
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10000

char str[MAX_N] = "\0";

int main()
{
    int len = 0, bor = 0, eol = 0;
    cin.getline(str, MAX_N);    // ���ж���
    len = strlen(str);
    bor = (len + 1) / 2;    // Beginning of right
    eol = len / 2;          // End of left
    for (int i = 1; i < eol; i++)
        for (int j = 0; j < i; j++)
            if (str[j] < str[i])
            {
                str[i] = str[i] ^ str[j];
                str[j] = str[i] ^ str[j];
                str[i] = str[i] ^ str[j];
            }
    for (int i = bor; i < len; i++)
        cout << str[i];
    if (len % 2)
        cout << str[eol];
    for (int i = 0; i < eol; i++)
        cout << str[i];
    return 0;
}
