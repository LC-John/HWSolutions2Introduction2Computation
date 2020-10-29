/*****
����
    һ������STUDENT_NUM��ѧ��������ʹ�á��ṹ���͡���дһ�� �������ȡѧ����ID��������ġ���ѧ�ɼ���Ȼ�����ÿ��ͬѧ
    ���ܷ֡�����ܷ�����ǰ��λ��ͬѧ��ѧ�ź��ܷ֡�
��������
    ��һ������Ϊѧ������n��n����1��С��100000��
    �Ժ�ÿ3�����ִ���һ��ѧ����ѧ�ţ����ĳɼ�����ѧ�ɼ�
�������
    ÿ��һ��ѧ�����ֱ�������ǰ����ѧ����ѧ�ź��ܳɼ���ѧ�ź��ܳɼ�֮���Կո���䡣
��������
    10
    1 78 82
    2 78 92
    3 87 89
    4 84 86
    5 87 81
    6 92 89
    7 90 76
    8 94 81
    9 79 88
    10 86 88
�������
    6 181
    3 176
    8 175
*****/

#include <iostream>
using namespace std;

#define MAX_N 100100
#define TOP_K 3

struct Student
{
    int id;
    int sum;
} stu[MAX_N];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c, m;
        cin >> stu[i].id >> c >> m;
        stu[i].sum = c + m;
    }
    for (int i = 0; i < TOP_K; i++)     // ֻ��Ҫ�ҵ�ǰTOP_K��Ϳ���
        for (int j = i + 1; j < n; j++) // û�б�Ҫȫ������
            if (stu[j].sum > stu[i].sum)
            {
                stu[i].id = stu[i].id ^ stu[j].id;
                stu[j].id = stu[i].id ^ stu[j].id;
                stu[i].id = stu[i].id ^ stu[j].id;
                stu[i].sum = stu[i].sum ^ stu[j].sum;
                stu[j].sum = stu[i].sum ^ stu[j].sum;
                stu[i].sum = stu[i].sum ^ stu[j].sum;
            }
    for (int i = 0; i < TOP_K; i++)
        cout << stu[i].id << " " << stu[i].sum << endl;
    return 0;
}
