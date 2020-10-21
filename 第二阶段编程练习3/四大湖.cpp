/*****
描述
    我国有4大淡水湖。
    A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。
    B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。
    C说：洪泽湖最小，洞庭湖第三。
    D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。
    已知这4个湖的大小均不相等，4个人每人仅答对一个，
    请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。
关于输入
    无。
关于输出
    输出为4行，第1行为鄱阳湖的大小名次，从大到小名次分别表示为1、2、3、4；第2、3、4行分别为洞庭湖、太湖、洪泽湖的大小名次。
例子输入
例子输出
    3
    2
    1
    4
*****/

#include <iostream>
using namespace std;

int main()
{
    for (int poyang = 1; poyang <= 4; poyang++)
    for (int dongting = 1; dongting <= 4; dongting++)
    for (int tai = 1; tai <= 4; tai++)
    for (int hongze = 1; hongze <= 4; hongze++)
    {
        if (poyang == dongting || poyang == tai || poyang == hongze || dongting == tai || dongting == hongze || tai == hongze)
            continue;
        int A = int(dongting == 1) + int(hongze == 4) + int(poyang == 3);
        int B = int(hongze == 1) + int(dongting == 4) + int(poyang == 2) + int(tai == 3);
        int C = int(hongze == 4) + int(dongting == 3);
        int D = int(poyang == 1) + int(tai == 4) + int(hongze ==2) + int(dongting == 3);
        if (A == B && B == C && C == D && D == 1)
            cout << poyang << endl << dongting << endl << tai << endl << hongze << endl;
    }
    return 0;
}
