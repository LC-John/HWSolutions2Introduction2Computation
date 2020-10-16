/*****
描述
    读取圆柱体的底面半径r和高h，求圆柱体的表面积。
关于输入
    输入半径r和高h，均是双精度浮点数
关于输出
    输出的值也是双精度浮点数，保留小数点后3位，格式见样例。
例子输入
    3.5 9
例子输出
    Area = 274.889
提示
    必须取pi＝3.14159。
*****/

#include <cstdio>

#define PI 3.14159

int main()
{
    double r, h;
    scanf("%lf %lf", &r, &h);
    printf("Area = %.3lf", PI * r * 2 * h + 2 * PI * r * r);
    return 0;
}
