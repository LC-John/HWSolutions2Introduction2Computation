/*****
����
    ����һ�����ӣ�һ�У����������е�ÿһ�����ʷ�ת�����
��������
    ֻ��һ�У�Ϊһ���ַ�����������500���ַ�������֮���Կո������
�������
    ��תÿһ�����ʺ���ַ���
��������
    hello world
�������
    olleh dlrow
��ʾ
    1. ÿ�����Ӷ�ֻ��һ�У���һ��ֻ�����ո����ĸ���ַ�����
    2. �����뵥�ʼ�Ŀո���ܲ�ֻһ����
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 200

char str[MAX_N] = "\0";
int len = 0;

int main()
{
    int idx = 0;
    cin.getline(str, MAX_N);
    len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] == ' ')
            str[i] = '\0';
    for (int i = 0; i < len; i++)
    {
        if (str[i] != '\0')
        {
            reverse(str + i, str + i + strlen(str + i));    // ��ת����
            i += strlen(str + i);
        }
    }
    for (int i = 0; i < len; i++)
        if (str[i] == '\0')
            cout << " ";
        else
            cout << str[i];
    return 0;
}
