/*****
����
    һ����������������ܱ�3��������������ʮ���Ʊ�ʾ����ĳ��λ���ϵ�����Ϊ3�������Ϊ��3��ص������ָ���һ��������n(n<100),�ж�n�Ƿ�����3��ص�����
��������
    ����Ϊһ�У�������n,n<100
�������
    ���Ϊһ�У����nΪ��3��ص����������TRUE���������FALSE
��������
    3
    10
    31
�������
    TRUE
    FALSE
    TRUE
*****/

#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        bool flag = true;
        if (num % 3 == 0)
        {
            cout << "TRUE" << endl;
            continue;
        }
        for (int i = num; i > 0; i /= 10)
            if (i % 10 == 3)
            {
                cout << "TRUE" << endl;
                flag = false;
                break;
            }
        if (flag)
            cout << "FALSE" << endl;
    }
    return 0;
}
