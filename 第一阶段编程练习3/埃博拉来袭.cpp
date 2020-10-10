/*****
描述
    A国出现了埃博拉疫情，第1天有N人被感染。每个病人在被感染的第2天开始感染其它健康人，每个病人每天可以感染X个健康人，病人在被感染的第Y天死去（死去的当天不再感染他人，也不计入当天存活人数）。求出第K天时，该国有多少被感染且活着的病人？
关于输入
    输入的第一行为3个整数，用空格分隔：N，第1天的感染人数，0 < N < 10；X，每人每天感染健康人的数量，0 < X < 10；Y，病人被感染到死去的天数，2 < Y < 10。
    输入的第二行为1个整数K，即欲求感染人数的日期，0 < K < 10。
关于输出
    输出为1行，输出第K天时该国被感染且活着的病人的总数。
例子输入
    5 4 3
    6
例子输出
    6400
*****/

#include <iostream>
using namespace std;

#define MAX_N 100

void debug(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int patient[MAX_N] = {0}, new_patient[MAX_N] = {0}, X = 0, Y = 0, K = 0, N = 0;
    cin >> N >> X >> Y >> K;
    patient[0] = N;
    new_patient[0] = N;
    for (int i = 1; i < K; i++)
    {
        int infected = patient[i-1];
        if (i >= Y-1)
            infected -= new_patient[i-Y+1];
        new_patient[i] = infected * X;
        patient[i] = infected + new_patient[i];
    }
    //debug(patient, K);
    //debug(new_patient, K);
    cout << patient[K-1];
    return 0;
}
