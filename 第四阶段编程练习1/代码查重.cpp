/*****
����
    �����ĳְҵѧУ������һ����Ϊ������۵Ŀγ̡����ſγ̿����������ʦ��ͬѧ�����������మ��ʮ�ֺ�г��
    ֱ����һ�죬һ��ɥ�Ĳ��������д��һ��������س���֮ǰ����ܰ��г�Ĺ�ϵ��ʼ������ѧ�������������˱�
    ��������¼���������ΪT������ϵ���ŲҰ���
    ʮ���ȥ�ˣ�Ϊ���о�T������ϵ���ŲҰ���ʼĩ��P�����ʦ��ͬѧ��ʵ������ɥ�Ĳ��������д���˺�������
    �޹�ͬѧ�Ĳ��س���ļ򻯰汾��
    �������ݴ��룬�ֱ�ͳ�����ݴ����е�if��switch��while��for���������������ݴ�����if��switch������֮
    �ͣ���while��for֮�ͷֱ���ȣ����ж������ݴ������໥��Ϯ�����ɡ�����ֱɥ�Ĳ���
��������
    ��1��һ������n�������һ�ݴ��������
    ����2��n+1��Ϊ��һ�ݴ���
    ��n+2��һ������m������ڶ��ݴ��������
    ����n+3��n+m+2��Ϊ�ڶ��ݴ���
�������
    һ��, ���ݴ������໥��Ϯ������, ���Yes���������No
��������
    3
    int main() {
        printf("Hello World!");
    }
    4
    int main()
    {
        printf("Hello World!");
    }
�������
    Yes
��ʾ
    We��ll be using a sophisticated cheat checker that compares handins between all students.
    Please don��t copy another student��s code.
*****/

#include <cstring>
#include <iostream>
using namespace std;

#define MAX_LEN 1000

const char word[4][MAX_LEN] = { "if", "switch", "while", "for" };

void remove_ws(char *s)
{
	int idx = 0;
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] != ' ' && s[i] != '\t')
			s[idx++] = s[i];
}

void CNT(char *s, int &cnt1, int &cnt2)
{
	remove_ws(s);
	for (int i = 0; i < s[i] != '\0'; i++)
		for (int j = 0; j < 4; j++)
		{
            int len = strlen(word[j]);
			if (strncmp(word[j], s + i, len) == 0 && s[i + len] == '(')
            {
				if (i < 2)
					cnt1 += 1;
				else
					cnt2 += 1;
			}
		}
}

int main()
{
	char s[MAX_LEN];
	int n1, n2, cnt11 = 0, cnt12 = 0, cnt21 = 0, cnt22 = 0;
	cin >> n1;
	cin.get();
	while (n1--) {
		cin.getline(s, MAX_LEN);
		CNT(s, cnt11, cnt12);
	}
	cin >> n2;
	cin.get();
	while (n2--) {
		cin.getline(s, MAX_LEN);
		CNT(s, cnt21, cnt22);
	}
	if (cnt11 == cnt21 && cnt12 == cnt22)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
	return 0;
}
