/*****
����
    ����һ���ַ����ж��Ǵ�д��ĸ����Сд��ĸ���Ǵ�д��ĸ���"upper case",��Сд��ĸ���"lower case",��������������"invalid input".
��������
    ����Ϊһ���ַ�
�������
    ���Ϊ�ַ�����Ϣ
��������
    s
�������
    lower case
*****/

#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    if (c <= 'Z' && c >= 'A')
        cout << "upper case";
    else if (c <= 'z' && c >= 'a')
        cout << "lower case";
    else
        cout << "invalid input";
    return 0;
}
