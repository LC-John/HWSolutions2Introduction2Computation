/*****
����
    �˹�����һֱ�Ǽ����ѧ��׷���һ���ܸߵľ��磬ȫ����ļ����ѧ�����������ڲ���Ŭ������ﵽ������硣
    �����Ҳ�����˹����ܡ��йء�
    ѧ�����������ͬѧ��Ӧ��֪������ѧ�е������ʽP�����ʣ�= U����ѹ��* I��������������������е���������ֵ��������ֵ
    ���Ǻ�������ģ�������Ǳ��������
��������
    ��Ȼ���˹����ܣ���Ҫ������Ŀ��ֱ�Ӹ��������е�ĳ����ֵ��
    ����ĵ�һ����һ����������ʾ�ж�����������ݡ�����ÿһ����һ��������ݣ��ֱ�Ϊһ��Ӣ�ľ��ӡ�����Ҫ����ʶ����֪��δ
    ֪���������δ֪������Ҫ˵�����ǣ�������I��U��P��������������֪������һ������I=xA, U=xV��P=xW��������ʽ������ע��
    ��λ�Լ���Сд�����������ı��ʽ�У����ܻ��ڵ�λ��A��V��W����ǰ����ֱ�ʾ����������ĸm��k��M���ֱ��ʾ����ǧ���ס�
�������
    ����ÿһ�����ݣ������¸�ʽ������У�
    �������"Problem #k"��k��ʾ��ǰ�ǵ�k��������ݡ�
    Ȼ������һ�������������Ҫ��λ����ΪA��V����W�����ұ�����λС����
    ��������һ�����С�
    ������Բμ����������
��������
    3
    If the voltage is U=200V and the current is I=4.5A, which power is generated?
    A light-bulb yields P=100W and the voltage is U=220V. Compute the current, please.
    bla bla bla lightning strike I=2A bla bla bla P=2.5MW bla bla voltage?
�������
    Problem #1
    P=900.00W

    Problem #2
    I=0.45A

    Problem #3
    U=1250000.00V
��ʾ
    ��ʾ�����ֺ����m��k��M���ֱ����0.001�� 1000��1000000.
    ���磺2m = 2 * 0.001
*****/

#include <iostream>
#include <iomanip>
using namespace std;

double get_value()
{
    double val = 0;
    char c = '\0';
    cin >> val;
    c = cin.get();
    switch(c)
    {
    case 'm': return val * 0.001;
    case 'k': return val * 1000;
    case 'M': return val * 1000000;
    default: return val;
    }
}

int main()
{
    int n;
    cin >> n; cin.get();
    for (int _case = 1; _case <= n; _case++)
    {
        double P = -1, U = -1, I = -1;
        char c = '\0', last_c = '\0';
        while (c = cin.get())
        {
            if (c == '\n')
                break;
            if (c == '=' && last_c == 'I')
                I = get_value();
            if (c == '=' && last_c == 'U')
                U = get_value();
            if (c == '=' && last_c == 'P')
                P = get_value();
            last_c = c;
        }
        cout << "Problem #" << _case << endl;
        if (P < 0)
            cout << "P=" << fixed << setprecision(2) << U * I << "W" << endl << endl;
        else if (I < 0)
            cout << "I=" << fixed << setprecision(2) << P / U << "A" << endl << endl;
        else
            cout << "U=" << fixed << setprecision(2) << P / I << "V" << endl << endl;
    }
    return 0;
}
