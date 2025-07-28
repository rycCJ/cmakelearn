
#include <iostream>
#include "my_pro_project/cycle_list.hpp" //相应的函数在此文件夹
using namespace std;

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