
#include <iostream>
#include "my_pro_project/Linked_List.hpp" //相应的函数在此文件夹
#include <unordered_map>
using namespace std;
// 方法一：龟兔赛跑

bool Solution1::hasCycle(ListNode *head)
{
    ListNode *fast, *slow, *prev;
    // prev->next = head;
    // 危险！若 head 是 nullptr，head->next 会直接解引用空指针
    /*空指针解引用是因为对未指向合法内存的指针进行了内存访问。只要养成 “定义指针时初始化、使用指针前判空” 的习惯，99% 的空指针问题都能避免。
     *遇到段错误（SegFault）时，优先检查指针是否为 nullptr 再使用，问题往往迎刃而解。*/
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
// 方法二：使用哈希表
bool Solution1::cycle_map(ListNode *head)
{
    std::unordered_map<ListNode *, int> map;
    ListNode *temp;
    temp = head;
    while (temp != nullptr)
    {
        auto it = map.find(temp->next);
        if (it != map.end())
        {
            return true;
        }
        map[temp->next] = temp->val;
        temp = temp->next;
    }
    return false;
}

int main()
{
    /*一个环，返回1*/
    ListNode *a1st = new ListNode(3), *a2st = new ListNode(2), *a3st = new ListNode(3), *a4st = new ListNode(4), *a5st = new ListNode(5);
    a1st->next = a2st;
    a2st->next = a3st;
    a3st->next = a4st;
    a4st->next = a5st;
    a5st->next = a2st;
    /*没有环，返回0*/
    // ListNode *a1st = new ListNode(3);
    // a1st->next = nullptr;
    Solution1 solution1;
    bool result = solution1.hasCycle(a1st);
    cout << result << endl;
}