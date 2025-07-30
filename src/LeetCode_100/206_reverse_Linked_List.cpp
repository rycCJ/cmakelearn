#include <iostream>
// #include "my_pro_project/Linked_List.hpp" //相应的函数在此文件夹

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode *n)
{
    cout << "----------now is: ----------" << endl;
    while (n != NULL)
    {
        cout << n->val << endl;
        n = n->next;
    }
}
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while (cur != nullptr)
        {

            ListNode *temp = cur->next;

            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
int main()
{
    ListNode *a1st = new ListNode(1), *a2st = new ListNode(2), *a3st = new ListNode(3), *a4st = new ListNode(4), *a5st = new ListNode(5);
    a1st->next = a2st;
    a2st->next = a3st;
    a3st->next = a4st;
    a4st->next = a5st;
    a5st->next = nullptr;
    Solution solution;
    ListNode *value = solution.reverseList(a1st);
    printList(value);
    // cout
    //     << value->val << endl;
}