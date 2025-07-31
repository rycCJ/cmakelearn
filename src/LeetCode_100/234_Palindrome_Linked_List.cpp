
#include <iostream>
#include <vector>
#include "my_pro_project/Linked_List.hpp" //相应的函数在此文件夹

ListNode *Solution2::reverseList(ListNode *head)
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
/*方法一，快慢指针+反转链表*/
bool Solution2::isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    } // 快慢指针找中点：快指针走两步，慢指针走一步，快指针到达末尾时，慢指针指向中点。
    ListNode *secondHalf = reverseList(slow->next);
    ListNode *p1 = head;
    ListNode *p2 = secondHalf;
    bool result = true;
    while (result && p2 != nullptr) // 很值得学习的判别条件
    {
        if (p1->val != p2->val)
            result = false;
        p1 = p1->next;
        p2 = p2->next; // 只有当p2为空（nullptr）时，访问 p->next 才会导致空指针解引用错误
    }
    return result;
}
// 辅助函数：创建链表
ListNode *createList(const std::vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    Solution2 sol;

    // 测试用例 1: 空链表
    ListNode *head = nullptr;
    std::cout << "测试空链表: "
              << (sol.isPalindrome(head) ? "是回文" : "不是回文") << std::endl;

    // 测试用例 2: 单节点链表
    head = createList({5});
    std::cout << "测试单节点链表 [5]: "
              << (sol.isPalindrome(head) ? "是回文" : "不是回文") << std::endl;
    // 释放内存
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    // 测试用例 3: 偶数长度回文链表
    head = createList({1, 2, 2, 1});
    std::cout << "测试偶数长度回文链表 [1,2,2,1]: "
              << (sol.isPalindrome(head) ? "是回文" : "不是回文") << std::endl;
    // 释放内存
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    // 测试用例 4: 偶数长度非回文链表
    head = createList({1, 2, 3, 4});
    std::cout << "测试偶数长度非回文链表 [1,2,3,4]: "
              << (sol.isPalindrome(head) ? "是回文" : "不是回文") << std::endl;
    // 释放内存
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    // 测试用例 5: 奇数长度回文链表
    head = createList({1, 2, 1});
    std::cout << "测试奇数长度回文链表 [1,2,1]: "
              << (sol.isPalindrome(head) ? "是回文" : "不是回文") << std::endl;
    // 释放内存
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    // 测试用例 6: 奇数长度非回文链表
    head = createList({1, 2, 3});
    std::cout << "测试奇数长度非回文链表 [1,2,3]: "
              << (sol.isPalindrome(head) ? "是回文" : "不是回文") << std::endl;
    // 释放内存
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}