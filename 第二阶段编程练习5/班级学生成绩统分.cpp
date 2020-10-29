/*****
描述
    一个班有STUDENT_NUM名学生。请你使用“结构类型”编写一个 程序负责读取学生的ID号码和语文、数学成绩。然后计算每名同学
    的总分。输出总分排在前三位的同学的学号和总分。
关于输入
    第一个数字为学生总数n（n大于1，小于100000）
    以后每3个数字代表一个学生的学号，语文成绩、数学成绩
关于输出
    每行一个学生，分别是排名前三的学生的学号和总成绩，学号和总成绩之间以空格相间。
例子输入
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
例子输出
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
    for (int i = 0; i < TOP_K; i++)     // 只需要找到前TOP_K大就可以
        for (int j = i + 1; j < n; j++) // 没有必要全部排序
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
