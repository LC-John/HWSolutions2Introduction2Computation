/*****
����
    ��д���򣬶���һ��Ӣ��(Ӣ���в��������)�������е��ʵ�˳���Ų���������е����Կո�ָ���
��������
    ����Ϊһ���ַ������ַ����������Ϊ100��
�������
    ���Ϊ��Ҫ����������ַ���
��������
    I am a student
�������
    student a am I
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 200

char str[MAX_N] = "\0";
int len = 0;

int main()
{
    cin.getline(str, MAX_N);
    len = strlen(str);
    for (int l = len - 1; l >= 0; l--)
        if (str[l] == ' ')  // l�Ҳ�Ϊһ������
        {
            str[l] = '\0';  // ��str[l]��ǣ���ʱֱ�����l���Ĳ��֣��ᵽlΪֹ
            cout << str+l+1 << " "; // ���l�Ҳ�ĵ���
        }
    cout << str;     // �������ĵ���
    return 0;
}
