/*****
����
    �������Զ�������������纺���ϵġ��ǵ䣨�ǵ����Է��ף����������󣨱�����ѧ������Ӣ���ϵġ�SARS(Severe Atypical Respiratory Syndrome)����
    �ٶ�ĳ���ַ���A�е�ÿ���ַ���������һ���ַ���S�в�ͬ��λ�ã���Сд��ȫ��ͬ�������ַ��� A ���ַ���ǰ���ϵ�� S �в������ı䣬ͬʱ��A�ĳ���С
    ��S�ĳ��ȣ�����Ϊ A �� S ��һ�������������������������Դ������ж�ǰ��Ĵ��Ƿ��Ǻ��洮�Ŀ�����������ǣ������ YES��������� NO
��������
    ��1��Ϊ������Ŀn��
    ���� n ���У�ÿ����һ���ַ����������ð�ż�����ж���ߵĴ��Ƿ����ұߴ����ܵ���������ٶ���ߴ��ĳ��Ȳ�����30���ַ����ұߴ��ĳ��Ȳ�����300
    ���ַ���
�������
    ����n�ԣ����� n �������ÿ�ж�Ӧ�жϵĽ�������ǿ��ܵ���������YES��������� NO
��������
    6
    AB:ACDEbFBkBD
    AR:ACDBrT
    SARS:Severe Atypical Respiratory Syndrome
    ACDEFBD:AB
    ABD:ACDEDkBY
    ABBR:ACDEDkBRT
�������
    YES
    NO
    YES
    NO
    NO
    NO
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LEN 500

int main()
{
    int n;
    cin >> n;
    cin.get();
    for (int _case = 0; _case < n; _case++)
    {
        char abbr[MAX_LEN] = "\0", *str = NULL;
        int ai = 0;
        cin.getline(abbr, MAX_LEN);
        for (int i = 0; abbr[i] != '\0'; i++)
            if (abbr[i] == ':')
            {
                str = abbr + i + 1;
                abbr[i] = '\0';
                break;
            }
        // cout << abbr << " " << str << endl;
        if (strlen(abbr) >= strlen(str))
        {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; str[i] != '\0'; i++)
            if (abbr[ai] == '\0')
                break;
            else if (abbr[ai] == str[i])
                ai++;
        if (abbr[ai] == '\0')
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
