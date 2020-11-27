# 第三阶段编程练习3

## 前缀表达式

前缀表达式是三种表达式（前缀，中缀，后缀）之中最好计算的表达式，每个操作符都只需要利用其后的两个表达式或数值进行计算。递归函数如下。

```cpp
double func()
{
    char str[MAX_LEN] = "\0";
    double val = 0;
    scanf("%s", str);   // 读入当前的操作符或数字
    switch (str[0])
    {
    case '+': val = func() + func(); break; // 四种二元操作符
    case '-': val = func() - func(); break; // 利用其后的两个表达式计算
    case '*': val = func() * func(); break;
    case '/': val = func() / func(); break;
    default: val = atof(str); break;        // 不是操作符，直接返回数值
    }
    return val;
}
```

## 平衡矩阵

该题目中需要移动矩阵的某些行，直接移动的话操作比较复杂，可以采用偏移量的方法。原始的二维数组为arr，每一行左移的次数都存放在offset数组中，假设移动后的数组为arr_。那么很显然有arr_[i][j] == arr[i][(j + offset[i]) % n]。这样设计数据结构，使得移动这个操作非常简单。

在有了计算矩阵各列和的最大值的函数calc之后，可以写出递归函数如下，其中每一行都左移n次，恰好可以恢复到初始状态。

```cpp
void func(int idx)
{
	if (idx >= n)   // 所有行都操作过，终止并计算calc
    {
        int tmp = calc();
        if (res > tmp)
            res = tmp;
		return;
	}
	for (int i = 0; i < n; i++) // 左移n次
	{
		offset[idx] = i;
		func(idx + 1);  // 每一次移动都递归调用func
	}
	return;
}
```

## K进制数的子序列

题目可以分作两部分，第一部分在于使用大整数加法计算所有序列，第二部分在于五个一行的输出。大整数计算之前的作业中已经出现过多次，不再赘述。五个一行输出可以使用如下代码。

```cpp
for (int i = 0; i < m; i++)
{
    addone();   // 计算当前需要输出的K进制数
    cout << s;  // 输出该数字
    if (i != m - 1) // 若该数不是最后一个数
    {
        if (i % 5 == 4) // 第五个，换行
            cout << endl;
        else            // 否则输出逗号
            cout << ",";
    }
}
```