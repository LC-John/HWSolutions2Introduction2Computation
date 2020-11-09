/*****
����
    ����һ����ʼ���ּ��ϣ��������������ֲ�����
    1. ���һ���µ�����
    2. �������е�ǰ��С������ȡ���������ɾ�����������С�������ж����ֻȡ������һ����
��������
    �����ļ���һ��Ϊ����n��������n����������ʾ��ʼ�����ּ��ϡ�
    �����һ������m����ʾ�����ĸ�����������m�У�ÿ�б�ʾһ�������������������ʽ��
    ADD x����ʾ�����ּ��������һ��x
    EXTRACT-MIN����ʾȡ����ǰ���ּ�������С����
    ע�����ּ����е�����ʱ�����ظ���
    n>=0
    m>=0
    n+m<=200000
�������
    ����ÿһ��EXTRACT-MIN�������С����ֵ�������ǰEXTRACT-MIN����ʱ����Ϊ�գ������"NULL"
��������
    5
    1
    2
    1
    2
    3
    11
    EXTRACT-MIN
    EXTRACT-MIN
    EXTRACT-MIN
    ADD 1
    EXTRACT-MIN
    EXTRACT-MIN
    EXTRACT-MIN
    EXTRACT-MIN
    ADD 5
    EXTRACT-MIN
    EXTRACT-MIN
�������
    1
    1
    2
    1
    2
    3
    NULL
    5
    NULL
��ʾ
    �Լ�ʵ����Ӧ�����ݽṹ������ʹ��ϵͳ�Ŀ⺯����
*****/

#include <iostream>
using namespace std;

#define MAX_N 200000
#define MAX_LEN 20

int q[MAX_N] = {0}, n_q = 0;

int main()
{
    int n = 0;
    char op[MAX_LEN] = "\0";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[n_q++];
    cin >> n;
    for (int _case = 0; _case < n; _case++)
    {
        cin >> op;
        if (op[0] == 'A')   // "ADD"
        {
            cin >> q[n_q++];
        }
        else    // POP
        {
            if (n_q == 0)
                cout << "NULL" << endl;
            else
            {
                for(int i = 0; i < n_q - 1; i++)
                    if(q[i] < q[i+1])
                    {
                        q[i] = q[i] ^ q[i + 1];
                        q[i + 1] = q[i] ^ q[i + 1];
                        q[i] = q[i] ^ q[i + 1];
                    }
                cout << q[n_q - 1] << endl;
                n_q--;
            }
        }
    }
    return 0;
}
