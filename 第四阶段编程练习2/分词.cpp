/*****
描述
    给定一个包含n个单词的英文词典和m个只由英文字母组成的字符串。
    判断这些字符串能否由词典中的单词组成。
    比如词典中包含5个单词："Jim", "and", "cat","like", "dog"
    这些单词能组成"Jimlikecatanddog"、"doglikecatandcatlikedog"等，
    但是不能组成"catlikeme"
    为了简化问题，所有的字母都是小写,而且词典中的所有单词长度都一样。
关于输入
    第一行两个正整数，n和m（n，m都不超过100）；
    接下来n行，每行一个单词，每个单词长度不超过20；
    接下来m行，每行一个字符串，长度不超过1000；
关于输出
    m行，表示词库中的单词能否组成该字符串，能输出"Yes"，不能输出"No"。
例子输入
    10 5
    did
    not
    and
    but
    hit
    run
    cat
    dog
    pig
    cow
    cathitdoganddogrun
    doghitpigbutpigdidnotrun
    pighitcowandcowdidrun
    cowhitcatandcatcry
    catdogpigandcowarehungry
例子输出
    Yes
    Yes
    Yes
    No
    No
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_WORD_LEN 30
#define MAX_SENT_LEN 1010
#define MAX_N 110

char words[MAX_N][MAX_WORD_LEN] = {'\0'};
char sent[MAX_SENT_LEN] = "\0", *curr = NULL;

int main()
{
    int n = 0, m = 0, len = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    len = strlen(words[0]);
    for (int _case = 0; _case < m; _case++)
    {
        cin >> sent;
        curr = sent;
        while(*curr != '\0')
        {
            bool flag = false;
            for (int i = 0; i < n; i++)
                if (!strncmp(curr, words[i], len))
                {
                    flag = true;
                    curr += len;
                    break;
                }
            if (!flag)
                break;
        }
        if (*curr == '\0')
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
