/*****
描述
    输入一个布尔表达式，请你输出它的真假值。
    比如：( V | V ) & F & ( F | V )
    V表示true，F表示false，&表示与，|表示或，!表示非。
    上式的结果是F
关于输入
    输入包含多行，每行一个布尔表达式，表达式中可以有空格，总长度不超过1000
关于输出
    对每行输入，如果表达式为真，输出"V",否则出来"F"
例子输入
    ( V | V ) & F & ( F| V)
    !V | V & V & !F & (F | V ) & (!F | F | !V & V)
    (F&F|V|!V&!F&!(F|F&V))
例子输出
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
