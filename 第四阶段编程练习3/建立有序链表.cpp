/*****
����
    ����N��������ݣ�ÿ���������������������ɡ���ÿ�����ݹ���һ�������������ӱ�ͷ����������
    Ҫ�󣺲��������κ����������
��������
    �����һ�д���������ݵ�����N����������N�У�ÿ�а�������������
�������
    ������ͷ��������Ԫ�أ�ÿ������֮���ÿո�ָ���ֱ�������ĩβ��
��������
    1
    2 6 4 3 7 11 30 -1 44
�������
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
