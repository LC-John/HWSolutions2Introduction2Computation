# 第二阶段编程练习3

本次作业着重练习逻辑判断和布尔运算，题目难度都不大，甚至都可以手工运算得出。但是不要直接输出手工运算的结果，而是通过遍历所有可能的情况，判定其是否满足要求，完成题目。

## 发票统计

直接按要求统计即可，难度不大。

## 四大湖

经过手工运算，不难得到四个湖泊的排名为1,2,3,4。但是按照作业的要求，应该扫描所有可能的排名情况，然后判断是否符合题目要求，在满足条件时输出结果。代码如下。

```cpp
#include <iostream>
using namespace std;

int main()
{
    for (int poyang = 1; poyang <= 4; poyang++) // 四个湖泊的排名情况
    for (int dongting = 1; dongting <= 4; dongting++)
    for (int tai = 1; tai <= 4; tai++)
    for (int hongze = 1; hongze <= 4; hongze++)
    {
        if (poyang == dongting || poyang == tai || poyang == hongze     // 排名不能相同
            || dongting == tai || dongting == hongze || tai == hongze)
            continue;
        int A = int(dongting == 1) + int(hongze == 4)
            + int(poyang == 3);                         // A的说法中正确的个数
        int B = int(hongze == 1) + int(dongting == 4)
            + int(poyang == 2) + int(tai == 3);         // B的说法中正确的个数
        int C = int(hongze == 4) + int(dongting == 3);  // C的说法中正确的个数
        int D = int(poyang == 1) + int(tai == 4) 
            + int(hongze ==2) + int(dongting == 3);     // D的说法中正确的个数
        if (A == B && B == C && C == D && D == 1)       // 每个人都只说对一个时满足要求，输出
            cout << poyang << endl << dongting << endl << tai << endl << hongze << endl;
    }
    return 0;
}
```

## 点评赛车

同上思路，不再赘述。

## 跳水比赛

同上思路，不再赘述。

## 侃侃而谈的四位朋友

同上思路，不再赘述。