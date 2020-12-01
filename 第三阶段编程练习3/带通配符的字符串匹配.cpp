/*****
描述
    通配符是一类键盘字符，当我们不知道真正字符或者不想键入完整名字时，常常使用通配符代替一个或多个真正字符。
    通配符有问号(?)和星号(*)等，其中，“?”可以代替一个字符，而“*”可以代替零个或多个字符。
    你的任务是，给出一个带有通配符的字符串和一个不带通配符的字符串，判断他们是否能够匹配。
    例如，1?456 可以匹配 12456、13456、1a456，但是却不能够匹配23456、1aa456；
    2*77?8可以匹配 24457798、237708、27798。
关于输入
    输入有两行，每行为一个不超过20个字符的字符串，第一行带通配符，第二行不带通配符
关于输出
    如果两者可以匹配，就输出“matched”，否则输出“not matched”
例子输入
    1*456?
    11111114567
例子输出
    matched
*****/


#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 100

bool dp[MAX_LEN][MAX_LEN] = {false};
char s1[MAX_LEN] = "\0", s2[MAX_LEN] = "\0";

int main()
{
	cin >> s1 + 1 >> s2 + 1;
	s1[0] = ' ';
	s2[0] = ' ';

	dp[0][0] = true;
	for(int i = 1; s1[i] == '*'; i++)
		dp[i][0] = true;

	for(int i = 1; s1[i] != '\0'; i++)
		for(int j = 1; s2[j] != '\0'; j++)
		{
			if(s1[i] == '?')
                dp[i][j] = dp[i-1][j-1];
			else if(s1[i] == '*')
				dp[i][j] = (dp[i-1][j-1]||dp[i-1][j]||dp[i][j-1]);
			else if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1];
		}
	 if(dp[strlen(s1) - 1][strlen(s2) - 1])
        cout<<"matched"<<endl;
	 else
        cout<<"not matched"<<endl;
	return 0;
 }
