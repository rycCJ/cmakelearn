#include <iostream>
#include "my_pro_project/Linked_List.hpp" //相应的函数在此文件夹

ListNode *Solution1::detectCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    int index = 0;
    // 第一次相遇
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break;
        }
    }
    if (fast == nullptr || fast->next == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return nullptr;
    }
    fast = head;
    // 开始第二次相遇
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        index++;
    }
    std::cout << "返回索引为 " << index << " 的链表节点" << std::endl;
    return slow;
}

// 创建测试函数
void testDetectCycle(const std::string &testName, ListNode *head, ListNode *expectedEntry, Solution1 &solution)
{
    std::cout << "=== " << testName << " ===\n";
    ListNode *result = solution.detectCycle(head);
    if (result == expectedEntry)
    {
        std::cout << "✅ Passed\n\n";
    }
    else
    {
        std::cout << "❌ Failed - Expected: ";
        if (expectedEntry)
            std::cout << expectedEntry->val;
        else
            std::cout << "nullptr";
        std::cout << ", Got: ";
        if (result)
            std::cout << result->val;
        else
            std::cout << "nullptr";
        std::cout << "\n\n";
    }
}

int main()
{
    Solution1 solution;

    // Test 1: 空链表
    testDetectCycle("Test 1: Empty list", nullptr, nullptr, solution);

    // Test 2: 单节点，无环
    ListNode *singleNode1 = new ListNode(1);
    testDetectCycle("Test 2: Single node without cycle", singleNode1, nullptr, solution);
    delete singleNode1;

    // Test 3: 单节点，形成环
    ListNode *singleNode2 = new ListNode(2);
    singleNode2->next = singleNode2;
    testDetectCycle("Test 3: Single node with self cycle", singleNode2, singleNode2, solution);
    delete singleNode2; // 警告：这会泄露内存，因为有环

    // Test 4: 多节点，无环
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    testDetectCycle("Test 4: Multi-node list without cycle", n1, nullptr, solution);
    delete n1;
    delete n2;
    delete n3;

    // Test 5: 多节点，环入口是头节点
    ListNode *m1 = new ListNode(10);
    ListNode *m2 = new ListNode(20);
    ListNode *m3 = new ListNode(30);
    m1->next = m2;
    m2->next = m3;
    m3->next = m1; // 环入口是 m1
    testDetectCycle("Test 5: Cycle entry at head", m1, m1, solution);

    // Test 6: 多节点，环入口是中间节点
    ListNode *p1 = new ListNode(5);
    ListNode *p2 = new ListNode(6);
    ListNode *p3 = new ListNode(7);
    ListNode *p4 = new ListNode(8);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p2; // 环入口是 p2
    testDetectCycle("Test 6: Cycle entry at middle", p1, p2, solution);

    // ⚠️ 注意：有环的链表节点未 delete，避免 delete 后访问问题
    return 0;
}
