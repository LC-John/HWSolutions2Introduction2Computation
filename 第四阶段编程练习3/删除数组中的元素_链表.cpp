/*****
����
    ����N������������Щ��������M��ȵ�ɾ��
    �ٶ���������������Ϊ��1,3,3,0,-3,5,6,8,3,10,22,-1,3,5,11,20,100,3,9,3
    Ӧ�ý������һ�������У�������Ϊ20
    Ҫɾ��������3��ɾ���Ժ�������ֻʣ14��Ԫ�أ�1 0 -3 5 6 8 10 22 -1 5 11 20 100 9
    Ҫ�󣺱���ʹ������������ʹ������,Ҳ������ɾ��Ԫ��ֱ�����
        �����б������������ز�������������ɾ��Ԫ�أ����ɾ����������Ԫ�أ��ͷ�����
        ������Ҫ��ĳ���ʹͨ����Ҳ�ᱻ�۷�
��������
    �������3�У�
    ��һ����һ������n(1<=n<=200000)������������Ԫ�صĸ�����
    �ڶ��а���n�����������������е�n��Ԫ�ء�ÿ������֮���ÿո�ָ���ÿ��������ȡֵ��32λ�з���������Χ���ڡ�
    ��������һ������k�������ɾ��Ԫ�ص�ֵ��k��ȡֵҲ��32λ�з���������Χ�ڣ���
�������
    ���ֻ��1�У�
    �����������д�ɾ��Ԫ��ɾ���Ժ���������ڵ�ʣ��Ԫ�ص�ֵ��ÿ������֮���ÿո�ָ���
��������
    20
    1 3 3 0 -3 5 6 8 3 10 22 -1 3 5 11 20 100 3 9 3
    3
�������
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
