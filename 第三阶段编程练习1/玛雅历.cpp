/*****
描述
    上周末，M.A教授对古老的玛雅有了一个重大发现。从一个古老的节绳（玛雅人用于记事的工具）中，教授发现玛雅人使
    用了一个一年有365天的叫做Haab的日历。这个Haab日历拥有19个月。在开始的18个月，一个月有20天。这18个月的名字
    分别是pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab,
    cumhu. 这些月份中的日期用0到19表示。Haab历的最后一个月叫做uayet，它只有5天，用0到4表示。玛雅人认为这个日
    期最少的月份是不吉利的，在这个月法庭不开庭，人们不从事交易，甚至没有人打扫屋中的走廊。
    因为宗教的原因，还玛雅人使用了另一个日历，在这个日历中年被称为Tzolkin(holly年)，一年被分成13个不同的时期，
    每个时期20天长，每一天用一个数字和一个单词相组合的形式来表示。使用了20个单词：imix, ik, akbal, kan, chicchan,
    cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau。和13个数字1到13。
    注意：年中的每一天都有着明确的描述，比如，在一年的开始，日期如下描述：
    1 imix, 2 ik, 3 akbal, 4 kan, 5 chicchan, 6 cimi, 7 manik, 8 lamat, 9 muluk, 10 ok, 11 chuen, 12 eb,
    13 ben, 1 ix, 2 mem, 3 cib, 4 caban, 5 eznab, 6 canac, 7 ahau, and again in the next period 8 imix, 9 ik,
    10 akbal . . .
    Haab历和Tzolkin历中的年都被数字0，1，：：：表示，数字0表示世界的开始。所以第一天被表示成：
    Haab: 0. pop 0
    Tzolkin: 1 imix 0
    请帮助M.A.教授，为他写一个程序可以把Haab历转化成Tzolkin历。
关于输入
    Haab历中的数据由如下的方式表示：
    日期. 月份 年数
    第一行表示要转化的Haab历的数据量. 下面的每一行表示一个日期，年数小于5000。
关于输出
    Tzolkin历中的数据由如下的方式表示：
    天数字 天名称 年数
    第一行表示要转化的Haab历的数据量. 下面的每一行表示一个日期。
例子输入
    3
    10. zac 0
    0. pop 0
    10. zac 1995
例子输出
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
