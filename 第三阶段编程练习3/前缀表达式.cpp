/*****
����
    ǰ׺���ʽ��һ�ְ������ǰ�õ��������ʽ��������ͨ�ı��ʽ2 + 3��ǰ׺��ʾ��Ϊ+ 2 3��ǰ׺���ʽ��
    �ŵ��������֮�䲻�������ȼ���ϵ��Ҳ���������Ÿı������������(2 + 3) * 4��ǰ׺��ʾ��Ϊ* + 2 3 4��
    �������ǰ׺���ʽ��ֵ���������������+ - * /�ĸ���
��������
    ����Ϊһ�У������������������֮�䶼�ÿո�ָ����������Ǹ�������
�������
    ���Ϊһ�У����ʽ��ֵ��
    ��ֱ����printf("%f\n", v)������ʽ��ֵv��
��������
    * + 11.0 12.0 + 24.0 35.0
�������
    1357.000000
��ʾ
    ��ʹ��atof(str)���ַ���ת��Ϊһ��double���͵ĸ�������atof������stdlib.h�С�
    �����ʹ�ú����ݹ���õķ�����⡣
*****/

#include <cstdio>
#include <cstdlib>

#define MAX_LEN 100

double func()
{
    char str[MAX_LEN] = "\0";
    double val = 0;
    scanf("%s", str);
    switch (str[0])
    {
    case '+': val = func() + func(); break;
    case '-': val = func() - func(); break;
    case '*': val = func() * func(); break;
    case '/': val = func() / func(); break;
    default: val = atof(str); break;
    }
    return val;
}

int main()
{
    printf("%f\n", func());
    return  0;
}
