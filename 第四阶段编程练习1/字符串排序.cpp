/*****
����
    ��������ַ������ֵ�����������������
��������
    ��һ����һ��������n����ʾ�ַ�������������n<=1000��
    ������n��ÿ����һ����Сд��ĸ��ɵ��ַ������ַ����ĳ��Ȳ��ᳬ��1000��
�������
    ���n�У�ÿ�����һ���ַ�����Ҫ���ֵ������������
��������
    4
    zaa
    fe
    ef
    za
�������
    ef
    fe
    za
    zaa
��ʾ
    ���ֵ��򣺴������ַ�������λ��ʼ���׸�����ȵ��ַ������������ַ���Ӧ��asciiֵ�Ĵ�Сȷ���ַ����Ĵ�С��ϵ��
    ����ʹ��strcmp������ȷ�������ַ������ֵ��򣬷���1��ʾ����ĵ�һ���ַ����ֵ���󣬷���-1��ʾ�ڶ����ַ�����
    ����󣬷���0��ʾ�����ַ�����ȡ�
    �ڽ�������ָ��Ƚ��������ַ�����ö�
*****/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 2000
#define MAX_LEN 2000

char *str[MAX_N] = {NULL};
int n = 0;

bool cmp(char* a, char*b)
{
    if (strcmp(a, b) < 0)
        return true;
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        str[i] = new char[MAX_LEN];
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    for (int i = 0; i < n; i++)
        cout << str[i] << endl;
    return 0;
}
