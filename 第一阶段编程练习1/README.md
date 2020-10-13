# 第一阶段编程练习1

本次作业难度适中，对于条件分支语句和循环语句、数组操作等较为熟悉后即可快速完成。

Repo中提供的做法可能不是最直观的方法，需要额外思考才能理解。下面对于各个题目进行简要的解释。

## 北京地铁

掌握IF-ELSEIF-ELSE分支后即能解决的问题，参考代码即可。

```cpp
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int expense = 0, dist = 0;
    double price = 0;
    cin >> expense >> dist;
    if (dist <= 6)  // 第一组分支，计算价格
        price = 3;
    else if (dist <= 12)
        price = 4;
    else if (dist <= 32)
        price = 4 + ceil((dist-12.)/10.);
    else
        price = 4 + 2 + ceil((dist-32.)/20.);
    if (expense >= 100 && expense < 150)    // 第二组分支，计算打折
        price *= 0.8;
    else if (expense >= 150 && expense < 400)
        price *= 0.5;
    cout << setiosflags(ios::fixed) << setprecision(2) << price << endl;
    return 0;
}
```

## 房价vs年薪

掌握FOR循环后即能解决的问题。代码中出现了两个return，第一个为可以买房，直接退出。

```cpp
#include <iostream>
using namespace std;

int main()
{
    int saving = 0, salary = 0, price = 0;
    cin >> salary >> price;
    for (int i = 1; i <=100; i++)
    {
        saving += salary;
        if (saving >= price)
        {
            cout << i;
            return 1;
        }
        saving *= 1.08;
        price *= 1.1;
    }
    cout << "Forget it.";
    return 0;
}
```

## 斐波那契数列

经典题目，可以递归也可以循环。计算fib数列的方法就是fib[i]=fib[i-1]+fib[i-2], (i>1), fib[1]=1, fib[0]=1。

代码中没有在一开始就把fib都算出来，而是在查询时发现没算到查询的idx位置时才继续计算fib。

```cpp
#include <iostream>
using namespace std;

#define MAX_N 100

int main()
{
    int fib[MAX_N] = {1, 1}, n_fib = 2, n = 0, idx = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> idx;
        if (idx > n_fib)
            for (int j = n_fib; j < idx; j++)
                fib[j] = fib[j-1] + fib[j-2];
        cout << fib[idx-1] << endl;
    }
    return 0;
}
```

## 最受欢迎的医生

参考代码即可。数组一般定义大一些。

```cpp
#include <iostream>
using namespace std;

#define MAX_N 100

int main()
{
    int doc[MAX_N] = {0}, n = 0, vote = 0, idx = 0, max_vote = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> vote;
        doc[vote]++;
        if (doc[vote] > max_vote)
        {
            max_vote = doc[vote];
            idx = vote;
        }
    }
    cout << idx;
    return 0;
}
```

## 点和正方形的关系

参考代码即可。注意输入格式里有逗号。

```cpp
#include <iostream>
//#include <cstdio>
using namespace std;

int main()
{
    double x, y;
    char ch;
    // 使用一个char类型变量来读入逗号
    cin >> x >> ch >> y;
    // 使用scanf可以限定输入格式，跳过逗号等符号
    //scanf("%lf,%lf", &x, &y);
    if (x >= -1 && x <= 1 && y >= -1 && y <= 1)
        cout << "yes";
    else
        cout << "no";
    return 0;
}
```

## 能被357整除的数

参考代码里没有使用写死的方法，而是使用数组，这样可以扩展。

```cpp
#include <iostream>
using namespace std;

#define MAX_N 100

int main()
{
    int div[MAX_N] = {3, 5, 7}, n_div = 3, num = 0;
    bool flag = true;
    cin >> num;
    // 这是一种可以扩展的写法，不管是多少个数，都可以用循环解决
    for (int i = 0; i < n_div; i++)
        if (num % div[i] == 0)
        {
            if (flag)
                cout << div[i];
            else
                cout << " " << div[i];
            flag = false;
        }
    if (flag)
        cout << "n";
    return 0;
}
```