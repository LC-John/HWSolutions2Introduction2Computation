/*****
����
    ������������ĳ˷���n*m�׵ľ���A����m*k�׵ľ���B�õ��ľ���C��n*k�׵ģ�
    ��C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + ���� +A[i][m-1]*B[m-1][j](C[i][j]��ʾC�����е�i�е�j��Ԫ��)
��������
    ��������G�����������ݵ�����
    ÿ������������룺
    ��һ��Ϊn, m, k����ʾA������n��m�У�B������m��k�У�n, m, k��С��100
    Ȼ���Ⱥ�����A��B��������A����n��m�У�B����m��k�У�������ÿ��Ԫ�ز������10000
�������
    ���ÿ�����ݣ����n��k�е�C����
��������
    1
    3 2 3
    1 1
    1 1
    1 1
    1 1 1
    1 1 1
�������
    2 2 2
    2 2 2
    2 2 2
��ʾ
    ע��ÿ�����һ������ߵĿո�Ҫ���
*****/

#include <iostream>
using namespace std;

#define MAX_N 200

double** new_matrix(int n, int m, bool input)
{
    double **A = new double*[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[m];
        for (int j = 0; j < m; j++)
            if (input)
                cin >> A[i][j];
            else
                A[i][j] = 0;
    }
    return A;
}

int main()
{
    int n_case = 0;
    cin >> n_case;
    while(n_case--)
    {
        double **A = NULL, **B = NULL, **C = NULL;
        int n = 0, m = 0, l = 0;
        cin >> n >> m >> l;
        A = new_matrix(n, m, true);
        B = new_matrix(m, l, true);
        C = new_matrix(n, l, false);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < l; j++)
                for (int k = 0; k < m; k++)
                    C[i][j] += A[i][k] * B[k][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < l; j++)
            {
                cout << C[i][j];
                if (j < l - 1)
                    cout << " ";
                else
                    cout << endl;
            }

    }
    return 0;
}
