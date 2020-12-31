/*****
描述
    给定N组测试数据，每组测试数据由若干整数组成。用每组数据构成一个有序链表，并从表头输出这个链表。
    要求：不允许用任何数组操作。
关于输入
    输入第一行代表测试数据的组数N。接下来的N行，每行包含若干整数。
关于输出
    从链表头输出链表的元素，每个数据之间用空格分隔，直到链表的末尾。
例子输入
    1
    2 6 4 3 7 11 30 -1 44
例子输出
    -1 2 3 4 6 7 11 30 44
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
    int n_case = 0;
    cin >> n_case;
    while (n_case--)
    {
        ListNode *root = new ListNode;
        ListNode *curr = root;
        curr->next = NULL;
        while (cin >> curr->val)
        {
            if (cin.get() == '\n')
                break;
            curr->next = new ListNode;
            curr->next->next = NULL;
            curr = curr->next;
        }
        for (ListNode *i = root; i; i = i->next)
            for (ListNode *j = i->next; j; j = j->next)
                if (i->val > j->val)
                {
                    i->val = i->val ^ j->val;
                    j->val = i->val ^ j->val;
                    i->val = i->val ^ j->val;
                }
        output_chain(root, true);
        delete_chain(root);
    }
    return 0;
}
