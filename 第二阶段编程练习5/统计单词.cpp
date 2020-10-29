/*****
����
    �������Ϣ�����ⲻ��Ҫ�漰���ı���������⣬�����ڶദ��ʽ�ж�һ�䣨�Σ����е�������ͳ���Ƿǳ�����Ҳ��ʮ����Ҫ��һ�����ڡ�
��������
    һ�仰����Ӣ����ĸ�����ּ����ñ�������ɡ�
�������
    ͳ�ƾ����и����ʳ��ֵĴ��������������ھ����е�һ�γ��ֵ�˳�������
    ������������У�ÿһ����һ�����ʣ��ո��ٸ��Ÿõ����ھ����г��ֵĴ�����
��������
    A truly great book should be read in youth, again in maturity and once more in old age, as a fine building should be seen by morning light, at noon and by moonlight.
�������
    A 1
    truly 1
    great 1
    book 1
    should 2
    be 2
    read 1
    in 3
    youth 1
    again 1
    maturity 1
    and 2
    once 1
    more 1
    old 1
    age 1
    as 1
    a 1
    fine 1
    building 1
    seen 1
    by 2
    morning 1
    light 1
    at 1
    noon 1
    moonlight 1
��ʾ
    ע��һЩϸ�ڱ��絥��֮�䲻һ�����ÿո�ѽ���ÿո�Ҳ��һ��ֻ��һ��ѽ��������������ǰ�����ı����ŵȣ�ע�⽫��Щ_��һ�����忼��_���Ϳ��Ա���Ƚ������ĳ����ˡ�^_^
    ��Ҽ��ͣ�
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10000
#define MAX_L 100

char str[MAX_L * MAX_N];
char word[MAX_N][MAX_L];
int cnt[MAX_N];
int n = 0;

bool is_letter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '\'';
}

int main()
{
    int len = 0;
    bool new_word = true;
    memset(word, 0, sizeof(word));
    memset(cnt, 0, sizeof(cnt));
    cin.getline(str, MAX_L * MAX_N);
    len = strlen(str);
    for (int i = 0; i < len; i++)
        if (!is_letter(str[i]))
            str[i] = '\0';
    for (int i = 0; i < len; i++)
        if (is_letter(str[i]))
        {
            if (new_word)
            {
                bool flag = true;
                new_word = false;
                for (int j = 0; j < n; j++)
                    if (strcmp(word[j], str+i) == 0)
                    {
                        cnt[j]++;
                        flag = false;
                        break;
                    }
                if (flag)
                {
                    strcpy(word[n], str+i);
                    cnt[n++] = 1;
                    // cout << str+i << endl;
                }
            }
        }
        else
            new_word = true;
    for (int i = 0; i < n; i++)
        cout << word[i] << " " << cnt[i] << endl;
    return 0;
}
