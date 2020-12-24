/*****
����
    ��һ���ַ�����ʾһ�λ������磺��CTATGGGTTT�������λ�������ƶȶ���Ϊ��������������󹫹��Ӵ��ĳ��ȡ�
    ���磺��CCTTGG���͡�TGGGC������󹫹��Ӵ�Ϊ��TGG�������ĳ���Ϊ3�������ǳơ�CCTTGG���͡�TGGGC��������
    ��Ϊ3���ָ������λ���Ҫ��������ǵ����ƶȡ�
��������
    �����һ�а���һ��������N��0
�������
    ����ÿ������������һ�У����а���һ����������ʾ��������ε����ƶȡ�
��������
    2
    CCCCC TTTTTGGGGGCC
    ACTGGG DDD
�������
    2
    0
��ʾ
    �����ʾ�������ĸ�������ܲ�ֻ��C��T��A��G���ĸ���ĸ��
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
