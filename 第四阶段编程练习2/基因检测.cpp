/*****
描述
    用一个字符串表示一段基因，例如：“CTATGGGTTT”。两段基因的相似度定义为它们所包含的最大公共子串的长度。
    例如：“CCTTGG”和“TGGGC”的最大公共子串为“TGG”，它的长度为3，则我们称“CCTTGG”和“TGGGC”的相似
    度为3。现给定两段基因，要求计算它们的相似度。
关于输入
    输入第一行包含一个正整数N（0
关于输出
    对于每组测试数据输出一行，该行包含一个整数，表示给定基因段的相似度。
例子输入
    2
    CCCCC TTTTTGGGGGCC
    ACTGGG DDD
例子输出
    2
    0
提示
    这里表示基因的字母个数可能不只是C、T、A、G这四个字母。
*****/

#include<iostream>
#include<cstring>
using namespace std;

#define MAX_LEN 1000

char gene1[MAX_LEN] = "\0", gene2[MAX_LEN] = "\0";

int main()
{
    int n_case;
    cin >> n_case;
    for(int _case = 0; _case < n_case; _case++)
    {
        cin >> gene1 >> gene2;
        int _max = 0x80000000;
        for(int i = 0; gene1[i] != '\0'; i++)
        {
            for(int j = 0; gene2[j] != '\0'; j++)
            {
                int num = 0;
                for (int ii = i, jj = j;
                        gene1[ii] == gene2[jj] && gene1[ii] != '\0' && gene2[jj] != '\0';
                        ii++, jj++, num++);
                if(num > _max)
                    _max = num;
            }
        }
        cout << _max << endl;
    }
    return 0;
}
