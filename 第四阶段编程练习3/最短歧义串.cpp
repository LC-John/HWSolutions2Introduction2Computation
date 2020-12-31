/*****
描述
    对于一个字符串,如果我们可以用两种不同的办法把它切分成单词的序列,那么我们说这个字符串是有歧义的.
    比如iskill,可以切分成is和kill,也可以切分成i和skill.
    现在给你一个单词表,请你构造出在这个单词表上的最短歧义串,即这个串可以用两种方案切分成单词表中的
    单词,要求歧义串尽可能短.
关于输入
    第一行是一个整数n(n<=100)表示词表的大小.
    接下来n行,每行一个单词,只包含数字和小写字母,长度不超过20.
关于输出
    输出最短歧义串,如果最短歧义串有多种可能,请输出字典序最小的那一个.
例子输入
    4
    i
    is
    kill
    skill
例子输出
    iskill
*****/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define MAX_N 110

string dict[MAX_N];
bool vis[MAX_N] = {false};
int n = 0, ans = 0x7fffffff;
string astr;


void dfs(string sstr, int templ, string tans)
{
        for(int i = 0; i < n; i++)
            if(!vis[i])
            {
                if(dict[i] == sstr)
                {
                    if(ans > templ + sstr.length())
                    {
                         ans = templ + sstr.length();
                         astr = tans + sstr;
                    }
                    return;
                }
                else if(dict[i].length() > sstr.length() && dict[i].find(sstr) == 0)
                {
                    vis[i] = true;
                    string tstr = dict[i].substr(sstr.length(), dict[i].length() - sstr.length());
                    dfs(tstr,templ + sstr.length(), tans + sstr);
                    vis[i] = false;
                }
                else if(dict[i].length() < sstr.length() && sstr.find(dict[i]) == 0)
                {
                    vis[i] = true;
                    string tstr = sstr.substr(dict[i].length(), sstr.length() - dict[i].length());
                    dfs(tstr,templ + dict[i].length(), tans + dict[i]);
                    vis[i] = false;
                }
            }
    return;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> dict[i];
    sort(dict, dict + n);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++){
            if(dict[i].find(dict[j], 0) == 0 && dict[i] != dict[j])
             {
                vis[i] = true;
                vis[j] = true;
                const string tstr = dict[i].substr(dict[j].length(), dict[i].length() - dict[j].length());
                dfs(tstr, dict[j].length(), dict[j]);
                vis[i] = false;
                vis[j] = false;
            }
        }
    }
    cout << astr;
    return 0;
}
