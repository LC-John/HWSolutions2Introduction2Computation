/*****
����
    һ����򵥵ļ�������֧��+, -, *, / �������㡣���迼���������Ϊ��������������ݺ����������ᳬ��int��ʾ�ķ�Χ��
��������
    ����ֻ��һ�У������������������е�1��2������Ϊ��������3������Ϊ��������+,-,*,/����
�������
    ���ֻ��һ�У�һ��������Ϊ��������Ȼ����
    1. ������ֳ���Ϊ0��������������Divided by zero!
    2. ���������Ч�Ĳ�����(����Ϊ +, -, *, / ֮һ�����������Invalid operator!
��������
    1 2 +
�������
    3
��ʾ
    ���Կ���ʹ��if��switch�ṹ��
*****/

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char c;
    cin >> a >> b >> c;
    if ('+' == c)
        cout << a + b;
    else if ('-' == c)
        cout << a - b;
    else if ('*' == c)
        cout << a * b;
    else if ('/' == c)
    {
        if (0 == b)
            cout << "Divided by zero!";
        else
            cout << a / b;
    }
    else
        cout << "Invalid operator!";
    // ����Ϊswitchд��
    /*
    switch(c)
    {
    case '+':
        cout << a + b; break;
    case '-':
        cout << a - b; break;
    case '*':
        cout << a * b; break;
    case '/':
        if (0 == b)
            cout << "Divided by zero!";
        else
            cout << a / b;
        break;
    default:
        cout << "Invalid operator!";
    }
    */
    return 0;
}
