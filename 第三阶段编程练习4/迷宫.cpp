/*****
����
    һ��Extense��ɭ����̽�յ�ʱ��С��������һ���Թ����Թ����Կ�������n * n�ĸ����ɣ�ÿ�����ֻ��2��״̬��
    .��#��ǰ�߱�ʾ����ͨ�к��߱�ʾ����ͨ�С�ͬʱ��Extense����ĳ�����ʱ����ֻ���ƶ�����������(����˵��������)
    �ĸ�����֮һ�����ڸ���ϣ�Extense��Ҫ�ӵ�A�ߵ���B�����ڲ��߳��Թ���������ܲ��ܰ쵽������������յ���һ
    ������ͨ��(Ϊ#)���򿴳��޷��쵽��
��������
    ��1���ǲ������ݵ�����k���������k�����롣ÿ��������ݵĵ�1����һ��������n (1 <= n <= 100)����ʾ�Թ��Ĺ�ģ
    ��n * n�ġ���������һ��n * n�ľ��󣬾����е�Ԫ��Ϊ.����#���ٽ�����һ����4������ha, la, hb, lb������A����
    ��ha��, ��la�У�B���ڵ�hb��, ��lb�С�ע�⵽ha, la, hb, lbȫ���Ǵ�0��ʼ�����ġ�
�������
    k�У�ÿ�������Ӧһ�����롣�ܰ쵽�������YES�������������NO����
��������
    2
    3
    .##
    ..#
    #..
    0 0 2 2
    5
    .....
    ###.#
    ..#..
    ###..
    ...#.
    0 0 4 0
�������
    YES
    NO
*****/

#include <iostream>
using namespace std;

#define ROAD '.'
#define WALL '#'

void debug_print(char** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j];
        cout << endl;
    }
}

bool dfs(char** a, int n, int curri, int currj, int tgti, int tgtj)
{
    int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
    if (curri == tgti && currj == tgtj) // �ҵ�����ֹ
        return true;
    if (curri < 0 || curri >= n || currj < 0 || currj >= n) // ���磬��ֹ
        return false;
    if (a[curri][currj] == WALL)        // �ߵ�ǽ���ֹ
        return false;
    a[curri][currj] = WALL;             // �߹���·����Ϊǽ�������ظ���
    for (int d = 0; d < 4; d++)
        if (dfs(a, n, curri+di[d], currj+dj[d], tgti, tgtj))
            return true;
    return false;
}

int main()
{
    int n_case = 0;
    cin >> n_case;
    while(n_case--)
    {
        int n = 0, si = 0, sj = 0, ei = 0, ej = 0;
        char **arr = NULL;
        cin >> n;
        arr = new char*[n];             // ��̬�����ά����
        for (int i = 0; i < n; i++)
        {
            arr[i] = new char[n];
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
        cin >> si >> sj >> ei >> ej;
        // debug_print(arr, n);
        if (arr[si][sj] == WALL || arr[ei][ej] == WALL)
        {
            cout << "NO" << endl;
            continue;
        }
        if (dfs(arr, n, si, sj, ei, ej))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        for (int i = 0; i < n; i++)
            delete[] arr[i];
        delete[] arr;
    }
    return 0;
}
