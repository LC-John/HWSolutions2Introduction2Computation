# 初步编程练习

本次作业基本没有难度，掌握C/C++语法后都可以完成。

需要掌握：

1. 基本的输入输出，包括cin和cout，有条件的同学可以学习scanf和printf；
2. 数据类型，包括int，char和float；
3. 比较符号，包括!=，\==，>，<，>=和<=等；
4. 与或非操作，包括&&，||和!等；
5. 分支if语句，具体形式为
   ```cpp
   if (Some_Condition)
   {
       // Do something here
   }
   else if (Some_Other_Condition) // This can be neglected
   {
       // Do something here
   }
   // There may be multiple ELSE-IFs
   else // This can be neglected
   {
       // Do something here
   }
   ```
6. 分支switch语句，具体形式为
    ```cpp
    switch (Some_Variable_or_Value)
    {
        case Case_Value_1:      // if (Some_Variable_or_Value == Case_Value_1)
            // Do something here
            break;
        case Case_Value_2:      // else if (Some_Variable_or_Value == Case_Value_2)
            // Do something here
            break;
        // There may be multiple cases
        default:                // else
            // Do something here
            break;
    }
    ```


重点注意：

1. 变量初始化，所有变量在定义时必须初始化。现在没有遇到问题是运气好，等到遇到未初始化引起的bug调试起来会非常痛苦；
2. 判断等于时，尤其注意\==和=的区别，建议将var == 0写作0 == var，这样即使写错也会直接发现；
3. switch语句中，每个case结束一定记得写break，否则会串入执行当前case后紧接的case的代码。