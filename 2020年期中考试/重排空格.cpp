/*****
����
    ����һ���ַ��� text�����ַ��������ɱ��ո��Χ�ĵ�����ɡ�ÿ��������һ�����߶��СдӢ����ĸ��ɣ�
    ������������֮�����ٴ���һ���ո�
    �����������пո�ʹÿ�����ڵ���֮��Ŀո���Ŀ��  ���  ����������  ���  ����Ŀ�������������ƽ
    ���������пո���  ������Ŀո�������ַ���ĩβ  ����Ҳ��ζ��������ַ���Ӧ����ԭ�ַ����ĳ�����ȡ�
��������
    һ����СдӢ����ĸ�Ϳո���ɵ��ַ�����
    �ַ������Ȳ�����1000�����ٰ���һ�����ʡ�
�������
    һ�к�ԭ�ַ���������ȵ��ַ�����
��������
      this   is  a sentence
�������
    this   is   a   sentence
*****/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_L 1010

char str[MAX_L] = "\0";

int main()
{
    int len = 0, n_space = 0, n_word = 0, n_print_space = 0, n_print_space_suffix = 0;
    bool flag = true;
    cin.getline(str, MAX_L);
    len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] == ' ')
        {
            n_space++;
            str[i] = '\0';
        }
        else if (str[i + 1] == ' ' || str[i + 1] == '\0')
            n_word++;
    if (n_word <= 1)
    {
        n_print_space = 0;
        n_print_space_suffix = n_space;
    }
    else
    {
        n_print_space = n_space / (n_word - 1);
        n_print_space_suffix = n_space % (n_word - 1);
    }
    for (int i = 0; i < len; i++)
        if (str[i] >= 'a' && str[i] <= 'z' && (i == 0 || str[i - 1] == '\0'))
        {
            if (flag)
                flag = false;
            else
                for (int j = 0; j < n_print_space; j++)
                    cout << " ";
            cout << str + i;
        }
    for (int j = 0; j < n_print_space_suffix; j++)
            cout << " ";
    return 0;
}
