/*****
����
    ����һ���������ʽ����������������ֵ��
    ���磺( V | V ) & F & ( F | V )
    V��ʾtrue��F��ʾfalse��&��ʾ�룬|��ʾ��!��ʾ�ǡ�
    ��ʽ�Ľ����F
��������
    ����������У�ÿ��һ���������ʽ�����ʽ�п����пո��ܳ��Ȳ�����1000
�������
    ��ÿ�����룬������ʽΪ�棬���"V",�������"F"
��������
    ( V | V ) & F & ( F| V)
    !V | V & V & !F & (F | V ) & (!F | F | !V & V)
    (F&F|V|!V&!F&!(F|F&V))
�������
    F
    V
    V
*****/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 1010

struct _OP
{
	char c;
	int level;
};

_OP ops[MAX_LEN] = {{0, 0}};
bool vals[MAX_LEN] = {0};
int n_op = 0, n_val = 0;

void cal()
{
    bool tmp = false;
	_OP cur = ops[--n_op];
	switch (cur.c)
	{
	case '!':
	    vals[n_val - 1] = !vals[n_val - 1];
		break;
	case '|':
	    tmp = vals[--n_val];
	    vals[n_val - 1] |= tmp;
		break;
	case '&':
	    tmp = vals[--n_val];
	    vals[n_val - 1] &= tmp;
		break;
	default:
		break;
	}
}

int main()
{
	char s[MAX_LEN];
	while (cin.getline(s, MAX_LEN))
    {
		int l = strlen(s);
		for (int i = 0; i < l; ++i)
		{
			if (s[i] == ' ')
				continue;
			if (s[i] == '(')
            {
                ops[n_op].c = '(';
                ops[n_op++].level = -1;
            }
			else if (s[i] == ')')
			{
				while (ops[n_op - 1].c != '(')
					cal();
				n_op--;
			}
            else if (s[i] == '|')
            {
				while (n_op != 0 && ops[n_op - 1].level > 0)
					cal();
                ops[n_op].c = s[i];
                ops[n_op++].level = 0;
			}
			else if (s[i] == '&')
            {
				while (n_op != 0 && ops[n_op - 1].level > 1)
					cal();
                ops[n_op].c = s[i];
                ops[n_op++].level = 1;
			}
			else if (s[i] == '!')
            {
				while (n_op != 0 && ops[n_op - 1].level > 2)
					cal();
				ops[n_op].c = s[i];
                ops[n_op++].level = 2;
			}
			else
                vals[n_val++] = s[i] == 'V';
		}
		while (n_op != 0)
			cal();
        if (vals[n_val - 1])
            cout << "V" << endl;
        else
            cout << "F" << endl;
	}
	return 0;
}
