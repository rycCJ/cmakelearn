
#include <iostream>
using namespace std;
/*方法一：链条A：a+b个数字
*链条B:c+b个数字
*第一条遍历：a,b,c
*第二条遍历：c,b,a
根据遍历个数相同，且指针相同从而找到链表交点。
*/
// Definition for singly-linked list.
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *point_A = headA;
        ListNode *point_B = headB;

        while (point_A != point_B)
        {
            point_A = point_A == nullptr ? headA : point_A->next;
            point_B = point_B == nullptr ? headB : point_B->next;
        }
        return point_A;
    }
};
int main()
{
    ListNode *head_A = new ListNode(4);
    ListNode *head_B = new ListNode(5);
    ListNode *A_2st = new ListNode(1);

    ListNode *B_2st = new ListNode(6), *B_3st = new ListNode(1);
    ListNode *common1 = new ListNode(8), *common2 = new ListNode(4), *common3 = new ListNode(5);

    head_A->next = A_2st;
    A_2st->next = common1;

    head_B->next = B_2st;
    B_2st->next = B_3st;
    B_3st->next = common1;

    common1->next = common2;
    common2->next = common3;
    // B_4st->next = A_4st;
    // B_5st->next = A_5st;

    // listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]
    Solution solution;
    ListNode *intersection = solution.getIntersectionNode(head_A, head_B);
    cout << intersection->val << endl;
}