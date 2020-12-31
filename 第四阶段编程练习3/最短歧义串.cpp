/*****
����
    ����һ���ַ���,������ǿ��������ֲ�ͬ�İ취�����зֳɵ��ʵ�����,��ô����˵����ַ������������.
    ����iskill,�����зֳ�is��kill,Ҳ�����зֳ�i��skill.
    ���ڸ���һ�����ʱ�,���㹹�����������ʱ��ϵ�������崮,����������������ַ����зֳɵ��ʱ��е�
    ����,Ҫ�����崮�����ܶ�.
��������
    ��һ����һ������n(n<=100)��ʾ�ʱ�Ĵ�С.
    ������n��,ÿ��һ������,ֻ�������ֺ�Сд��ĸ,���Ȳ�����20.
�������
    ���������崮,���������崮�ж��ֿ���,������ֵ�����С����һ��.
��������
    4
    i
    is
    kill
    skill
�������
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
