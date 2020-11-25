/*****
����
    ����ĩ��M.A���ڶԹ��ϵ���������һ���ش��֡���һ�����ϵĽ��������������ڼ��µĹ��ߣ��У����ڷ���������ʹ
    ����һ��һ����365��Ľ���Haab�����������Haab����ӵ��19���¡��ڿ�ʼ��18���£�һ������20�졣��18���µ�����
    �ֱ���pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab,
    cumhu. ��Щ�·��е�������0��19��ʾ��Haab�������һ���½���uayet����ֻ��5�죬��0��4��ʾ����������Ϊ�����
    �����ٵ��·��ǲ������ģ�������·�ͥ����ͥ�����ǲ����½��ף�����û���˴�ɨ���е����ȡ�
    ��Ϊ�ڽ̵�ԭ�򣬻�������ʹ������һ��������������������걻��ΪTzolkin(holly��)��һ�걻�ֳ�13����ͬ��ʱ�ڣ�
    ÿ��ʱ��20�쳤��ÿһ����һ�����ֺ�һ����������ϵ���ʽ����ʾ��ʹ����20�����ʣ�imix, ik, akbal, kan, chicchan,
    cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau����13������1��13��
    ע�⣺���е�ÿһ�춼������ȷ�����������磬��һ��Ŀ�ʼ����������������
    1 imix, 2 ik, 3 akbal, 4 kan, 5 chicchan, 6 cimi, 7 manik, 8 lamat, 9 muluk, 10 ok, 11 chuen, 12 eb,
    13 ben, 1 ix, 2 mem, 3 cib, 4 caban, 5 eznab, 6 canac, 7 ahau, and again in the next period 8 imix, 9 ik,
    10 akbal . . .
    Haab����Tzolkin���е��궼������0��1����������ʾ������0��ʾ����Ŀ�ʼ�����Ե�һ�챻��ʾ�ɣ�
    Haab: 0. pop 0
    Tzolkin: 1 imix 0
    �����M.A.���ڣ�Ϊ��дһ��������԰�Haab��ת����Tzolkin����
��������
    Haab���е����������µķ�ʽ��ʾ��
    ����. �·� ����
    ��һ�б�ʾҪת����Haab����������. �����ÿһ�б�ʾһ�����ڣ�����С��5000��
�������
    Tzolkin���е����������µķ�ʽ��ʾ��
    ������ ������ ����
    ��һ�б�ʾҪת����Haab����������. �����ÿһ�б�ʾһ�����ڡ�
��������
    3
    10. zac 0
    0. pop 0
    10. zac 1995
�������
    3
    3 chuen 0
    1 imix 0
    9 cimi 2801
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 20
#define MAX_L 20

const char tzol[MAX_N][MAX_L] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
const char haab[MAX_N][MAX_L] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };


int main()
{
	int k;
	cin >> k;
	cout << k << endl;
	while (k--)
    {
		int day, month, year;
		char c;
		char s[MAX_L];
		cin >> day >> c >> s >> year;
		for (int i = 0; i < 19; ++i)
			if (strcmp(haab[i], s) == 0)
				month = i;
		int D = month * 20 + day;
		D += year * 365;
		year = D / 260;
		D %= 260;
		month = D % 13;
		D = D % 20;
		cout << month + 1 << " " << tzol[D] << ' ' << year << endl;
	}
	return 0;
}
