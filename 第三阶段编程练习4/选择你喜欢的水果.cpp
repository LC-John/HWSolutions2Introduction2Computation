/*****
����
    �����б���������ˮ�������֣�Ҫ���û�����һ����ˮ���йصľ��ӡ��������Ѵ洢��ˮ��������������
    ���жϾ������Ƿ��������ˮ�������ơ�������������ô���"Brussels sprouts"�滻�����г��ֵ�ˮ
    �����ʣ�������滻��ľ��ӡ����������û�г�����Щˮ�������֣������"You must not enjoy fruit.".
    ��������ˮ��������Ϊ��apples, bananas, peaches, cherries, pears, oranges, strawberries.
��������
    �����ж��У�ÿ����һ���ַ�����ÿһ��������ֻ����һ��ˮ�����ƣ��������һ�������������ˮ����
    �ƻ��ظ�ˮ�����Ƶ������
�������
    �������ˮ�����ʣ����ô���"Brussels sprouts"�滻�����г��ֵ�ˮ�����ʣ�������滻��ľ��ӡ���
    ��������û�г�����Щˮ�������֣������"You must not enjoy fruit.".
��������
    I really love peaches on my cereal.
    I��d rather have a candy bar
    apples are wonderful with lunch
�������
    I really love Brussels sprouts on my cereal.
    You must not enjoy fruit.
    Brussels sprouts are wonderful with lunch
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 10000

char str[MAX_LEN] = "\0";
const int n_fruit = 7;
char fruit[n_fruit][MAX_LEN] = {"apples", "bananas", "peaches", "cherries", "pears", "oranges", "strawberries"};

int main()
{
    while(cin.getline(str, MAX_LEN))
    {
        bool flag = false;
        for (int i = 0; i < n_fruit; i++)
        {
            char* pos = strstr(str, fruit[i]);  // �ҵ��Ӵ�λ��
            if (!pos)
                continue;
            flag = true;
            for (char *c = str; c != pos; c += 1)
                cout << *c;
            cout << "Brussels sprouts";
            cout << pos + strlen(fruit[i]) << endl;
            break;
        }
        if (!flag)
            cout << "You must not enjoy fruit." << endl;
    }
    return 0;
}
