/*****
描述
    给定N个整数，将这些整数中与M相等的删除
    假定给出的整数序列为：1,3,3,0,-3,5,6,8,3,10,22,-1,3,5,11,20,100,3,9,3
    应该将其放在一个链表中，链表长度为20
    要删除的数是3，删除以后，链表中只剩14个元素：1 0 -3 5 6 8 10 22 -1 5 11 20 100 9
    要求：必须使用链表，不允许使用数组,也不允许不删除元素直接输出
        程序中必须有链表的相关操作：建立链表，删除元素，输出删除后链表中元素，释放链表
        不符合要求的程序即使通过，也会被扣分
关于输入
    输入包含3行：
    第一行是一个整数n(1<=n<=200000)，代表数组中元素的个数。
    第二行包含n个整数，代表数组中的n个元素。每个整数之间用空格分隔；每个整数的取值在32位有符号整数范围以内。
    第三行是一个整数k，代表待删除元素的值（k的取值也在32位有符号整数范围内）。
关于输出
    输出只有1行：
    将数组内所有待删除元素删除以后，输出数组内的剩余元素的值，每个整数之间用空格分隔。
例子输入
    20
    1 3 3 0 -3 5 6 8 3 10 22 -1 3 5 11 20 100 3 9 3
    3
例子输出
    1 0 -3 5 6 8 10 22 -1 5 11 20 100 9
*****/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void output_chain(ListNode* root, bool first)
{
    if (!root)
    {
        cout << endl;
        return;
    }
    if (first)
        cout << root->val;
    else
        cout << " " << root->val;
    output_chain(root->next, false);
    return;
}

void delete_chain(ListNode* root)
{
    for (ListNode *curr = root; curr; curr = root)
    {
        root = curr->next;
        delete curr;
        curr = root;
    }
}

int main()
{
    ListNode *root = new ListNode;
    ListNode *curr = root, *prev = NULL;
    int n = 0, del_num = 0;
    curr->next = NULL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> curr->val;
        if (i < n - 1)
        {
            curr->next = new ListNode;
            curr->next->next = NULL;
            curr = curr->next;
        }
    }
    cin >> del_num;

    if (!root)
    {
        output_chain(root, true);
        return 0;
    }
    for (prev = root, curr = root->next; curr; )
        if (curr->val == del_num)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    if (root->val == del_num)
    {
        curr = root;
        root = root->next;
        delete curr;
    }


    output_chain(root, true);
    delete_chain(root);
    return 0;
}
