
#include <iostream>
using namespace std;
// cycle_list

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast, *slow, *prev;
        //       prev->next = head;
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        slow = head;
        fast = head->next;
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};