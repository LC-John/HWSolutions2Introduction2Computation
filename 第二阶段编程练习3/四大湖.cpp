/*****
����
    �ҹ���4��ˮ����
    A˵����ͥ����󣬺������С��۶����������
    B˵���������󣬶�ͥ����С��۶�����ڶ���̫��������
    C˵���������С����ͥ��������
    D˵��۶�������̫����С��������ڶ�����ͥ��������
    ��֪��4�����Ĵ�С������ȣ�4����ÿ�˽����һ����
    ���̰���۶��������ͥ����̫�����������˳��������ǵĴ�С������
��������
    �ޡ�
�������
    ���Ϊ4�У���1��Ϊ۶�����Ĵ�С���Σ��Ӵ�С���ηֱ��ʾΪ1��2��3��4����2��3��4�зֱ�Ϊ��ͥ����̫����������Ĵ�С���Ρ�
��������
�������
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
