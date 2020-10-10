/*****
����
    A�������˰��������飬��1����N�˱���Ⱦ��ÿ�������ڱ���Ⱦ�ĵ�2�쿪ʼ��Ⱦ���������ˣ�ÿ������ÿ����Ը�ȾX�������ˣ������ڱ���Ⱦ�ĵ�Y����ȥ����ȥ�ĵ��첻�ٸ�Ⱦ���ˣ�Ҳ�����뵱�����������������K��ʱ���ù��ж��ٱ���Ⱦ�һ��ŵĲ��ˣ�
��������
    ����ĵ�һ��Ϊ3���������ÿո�ָ���N����1��ĸ�Ⱦ������0 < N < 10��X��ÿ��ÿ���Ⱦ�����˵�������0 < X < 10��Y�����˱���Ⱦ����ȥ��������2 < Y < 10��
    ����ĵڶ���Ϊ1������K���������Ⱦ���������ڣ�0 < K < 10��
�������
    ���Ϊ1�У������K��ʱ�ù�����Ⱦ�һ��ŵĲ��˵�������
��������
    5 4 3
    6
�������
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
