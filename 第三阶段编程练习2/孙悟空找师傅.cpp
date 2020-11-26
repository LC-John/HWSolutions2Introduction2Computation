/*****
����
    ����ʦ�֣�ʦ���ֱ�����ץ���ˣ�����ɳʦ��˵����������������Ϣ��������ǰȥ��ʦ�������ǵ�����������ֶ���
    ʱ���������ָ��Լ�����һ����ֻ�гɹ��ƽ��������ղ��ܾȳ�ʦ�����������ж����ܷ�ȳ�ʦ����
��������
    �����һ������������m��n����ʾ����Ϊm*n��С��0 < m,n <= 50��mΪ�У�nΪ�У�����������һ��m*n�ľ����ʾ��
    ��������0Ϊ�����п��ߵ�·��1Ϊǽ���������ߵ�λ�ã���2Ϊ��յ�λ�ã�3Ϊʦ����λ�á����ֻ���ĸ����е���
    �߷��򣺼����ϡ��¡����ң�����б�Խ��ߴ�Խ��ÿ�����������֮�䶼�ǿո�����
�������
    ���ֻ��һ�У�"Yes"��"No"��ʾ����Ƿ���Գɹ��ȳ�ʦ����������ߵ�ʦ����λ�ü��ɾȳ�ʦ������
��������
    8 7
    1 1 1 1 1 1 3
    1 0 0 0 0 0 0
    1 0 1 1 1 1 1
    1 0 0 0 1 1 1
    1 1 1 0 0 0 1
    1 0 0 0 1 0 1
    1 0 1 1 1 0 1
    2 0 1 1 1 0 0
�������
    Yes
*****/

#include <iostream>
using namespace std;

#define MAX_N 100
#define ROAD 0
#define WALL 1
#define VISITED 2
#define GOAL 3

int arr[MAX_N][MAX_N] = {0}, m = 0, n = 0;

bool func(int i, int j)
{
    bool ret = false;
    int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};
    for (int d = 0; d < 4; d++)
    {
        int _i = i + di[d], _j = j + dj[d];
        if (_i < 0 || _i >= m || _j < 0 || _j >= n) // ����
            continue;
        if (arr[_i][_j] == GOAL)    // �ҵ�
            return true;
        if (arr[_i][_j] != ROAD)      // ����·
            continue;
        arr[_i][_j] = VISITED;
        ret = ret || func(_i, _j);
        if (ret)
            return ret;
    }
    return ret;
}

int main()
{
    int x = 0, y = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == VISITED)
            {
                x = i;
                y = j;
            }
        }
    if (func(x, y))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
