/*****
����
    �ж�ĳ���Ƿ������ꡣ
��������
    ����ֻ��һ�У�����һ������a(0 < a < 3000)
�������
    һ�У������Ԫa�����������Y���������N
��������
    2006
�������
    N
*****/

#include <iostream>
using namespace std;

int main()
{
    int y = 0;
    cin >> y;
    if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0)
        cout << "Y";
    else
        cout << "N";
    return 0;
}
