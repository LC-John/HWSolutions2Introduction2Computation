/*****
����
    ����һ������n�����ʵ�Ӣ�Ĵʵ��m��ֻ��Ӣ����ĸ��ɵ��ַ�����
    �ж���Щ�ַ����ܷ��ɴʵ��еĵ�����ɡ�
    ����ʵ��а���5�����ʣ�"Jim", "and", "cat","like", "dog"
    ��Щ���������"Jimlikecatanddog"��"doglikecatandcatlikedog"�ȣ�
    ���ǲ������"catlikeme"
    Ϊ�˼����⣬���е���ĸ����Сд,���Ҵʵ��е����е��ʳ��ȶ�һ����
��������
    ��һ��������������n��m��n��m��������100����
    ������n�У�ÿ��һ�����ʣ�ÿ�����ʳ��Ȳ�����20��
    ������m�У�ÿ��һ���ַ��������Ȳ�����1000��
�������
    m�У���ʾ�ʿ��еĵ����ܷ���ɸ��ַ����������"Yes"���������"No"��
��������
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
�������
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
