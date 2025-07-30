
// #include <gtest/gtest.h>                  // 包含 Google Test 的主头文件
// #include "my_pro_project/Linked_List.hpp" // 包含我们要测试的库的头文件

// // 创建链表节点的辅助函数
// ListNode *createNode(int val)
// {
//     return new ListNode(val);
// }

// // 测试Solution1::hasCycle函数
// TEST(Solution1Test, HasCycle)
// {
//     Solution1 sol;

//     // 测试用例1: 空链表
//     ListNode *head1 = nullptr;
//     EXPECT_FALSE(sol.cycle_map(head1)); // 已修复：不会触发段错误

//     // 测试用例2: 单节点无环
//     ListNode *head2 = createNode(1);
//     head2->next = nullptr;
//     EXPECT_FALSE(sol.cycle_map(head2));
//     delete head2; // 释放内存

//     // 测试用例3: 多节点无环（1->2->3->nullptr）
//     ListNode *head3 = createNode(1);
//     head3->next = createNode(2);
//     head3->next->next = createNode(3);
//     head3->next->next->next = nullptr;
//     EXPECT_FALSE(sol.cycle_map(head3));
//     // 释放内存（从尾到头释放）
//     delete head3->next->next;
//     delete head3->next;
//     delete head3;

//     // 测试用例4: 单节点自环（1->1）
//     ListNode *head4 = createNode(1);
//     head4->next = head4; // 自环
//     EXPECT_TRUE(sol.cycle_map(head4));
//     head4->next = nullptr; // 断开环再释放
//     delete head4;

//     // 测试用例5: 多节点有环（1->2->3->2）
//     ListNode *head5 = createNode(1);
//     head5->next = createNode(2);
//     head5->next->next = createNode(3);
//     head5->next->next->next = head5->next; // 3->2 形成环
//     EXPECT_TRUE(sol.cycle_map(head5));
//     head5->next->next->next = nullptr; // 断开环
//     delete head5->next->next;
//     delete head5->next;
//     delete head5;
// }