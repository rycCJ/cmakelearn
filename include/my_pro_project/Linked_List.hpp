
#ifndef CYCLE_LIST_H
#define CYCLE_LIST_H

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1
{
public:
    bool hasCycle(ListNode *head);
    bool cycle_map(ListNode *head); // 返回值类型改为bool
};
class Solution2
{
public:
    ListNode *reverseList(ListNode *head);
    bool isPalindrome(ListNode *head);
};
#endif