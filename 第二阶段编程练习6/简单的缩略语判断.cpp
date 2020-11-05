/*****
描述
    各种语言都充满了缩略语。如汉语上的“非典（非典型性肺炎）”，“北大（北京大学）”，英语上的“SARS(Severe Atypical Respiratory Syndrome)”。
    假定某个字符串A中的每个字符出现在另一个字符串S中不同的位置（大小写完全相同），且字符串 A 中字符的前后关系在 S 中不发生改变，同时，A的长度小
    于S的长度，就认为 A 是 S 的一个可能缩略语。现在任意给定两对串，请判断前面的串是否是后面串的可能缩略语。若是，则输出 YES，否则，输出 NO
关于输入
    第1行为串对数目n；
    后面 n 行中，每行是一对字符串，其间以冒号间隔（判断左边的串是否是右边串可能的缩略语），假定左边串的长度不大于30个字符，右边串的长度不大于300
    个字符。
关于输出
    若有n对，则有 n 行输出，每行对应判断的结果。若是可能的缩略语，输出YES；若否，输出 NO
例子输入
    6
    AB:ACDEbFBkBD
    AR:ACDBrT
    SARS:Severe Atypical Respiratory Syndrome
    ACDEFBD:AB
    ABD:ACDEDkBY
    ABBR:ACDEDkBRT
例子输出
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
