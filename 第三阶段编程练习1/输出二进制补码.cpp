/*****
����
��������int�����������ÿ�������Ķ����Ʋ��롣
��������
�����������У������һ���⣬ÿ�а���һ��int�����������һ�н�����һ����������ĸ����־��������������Ǳ�֤���������������int�ͱ����ı�ʾ��Χ
�������
����ÿ����������������һ�У����������Ĳ����ʾ��
��������
1

7

200

-45

h
�������
00000000000000000000000000000001

00000000000000000000000000000111

00000000000000000000000011001000

11111111111111111111111111010011
*****/

#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_LEN 100
#define INT_LEN 32

int main()
{
    char str[MAX_LEN] = "\0";
    while(cin >> str)
    {
        int num = 0, bin[MAX_LEN] = {0};
        if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
            break;
        sscanf(str, "%d", &num);
        for (int idx = 0; idx < INT_LEN; num = num >> 1)
            bin[idx++] = num & 1;
        for (int i = INT_LEN - 1; i >= 0; i--)
            cout << bin[i];
        cout << endl;
    }
    return 0;
}
