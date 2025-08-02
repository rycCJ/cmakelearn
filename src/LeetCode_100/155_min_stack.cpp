#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
// 方法二
#include <utility>   // for std::pair
#include <algorithm> // for std::min
// class MinStack
// {
// private:
//     std::stack<int> sta;
//     std::stack<int> Min_sta;

// public:
//     MinStack()
//     {
//     }

//     void push(int val)
//     {
//         sta.push(val);
//         if (Min_sta.empty())
//             Min_sta.push(val);
//         else                                                                        // aaa
//             val >= Min_sta.top() ? Min_sta.push(Min_sta.top()) : Min_sta.push(val); // 当sta中还没有值时sta.top是什么
//     }

//     void pop()
//     {
//         if (!sta.empty())
//         {
//             Min_sta.pop();
//             sta.pop();
//         }
//     }

//     int top()
//     {
//         return sta.top();
//     }

//     int getMin()
//     {
//         return Min_sta.top();
//     }
//     bool empty()
//     {
//         // 我们可以通过判断主栈 sta 是否为空，来确定整个 MinStack 是否为空
//         return sta.empty();
//     }
// };

// 方法二
class MinStack
{
private:
    std::stack<std::pair<int, int>> data_stack;

public:
    MinStack2()
    {

        int min_num;
    }
    void push(int val)
    {
        if (!data_stack.empty())
        {
            int current_num = data_stack.top().second;
            int min_num = std::min(val, current_num);
            data_stack.push({val, min_num});
        }
        else
        {
            data_stack.push({val, val});
        }
    }
    void pop()
    {
        data_stack.pop();
    }
    int top()
    {
        return data_stack.top().first;
    }
    int getMin()
    {
        return data_stack.top().second;
    }
    bool empty()
    {
        return data_stack.empty();
    }
};
// 测试

// 一个辅助函数，方便打印栈的状态
void printStatus(MinStack &stack, const std::string &operation)
{
    std::cout << "操作: " << operation << std::endl;
    // LeetCode环境下，对空栈调用top()或getMin()是未定义行为，我们在这里避免
    if (!stack.empty())
    { // 我们虚构一个empty()方法来让测试代码更安全
      // 在你的类中你不需要实现 empty()
        std::cout << "栈顶元素 (top): " << stack.top() << std::endl;
        std::cout << "当前最小值 (getMin): " << stack.getMin() << std::endl;
    }
    else
    {
        std::cout << "栈已空" << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}
int main()
{
    // --- 测试用例 1: 基本功能测试 ---
    std::cout << "=========== 测试用例 1: 基本功能 ===========" << std::endl;
    MinStack minStack1;
    minStack1.push(-2);

    printStatus(minStack1, "push(-2)");
    minStack1.push(0);
    printStatus(minStack1, "push(0)");
    minStack1.push(-3);
    printStatus(minStack1, "push(-3)");
    minStack1.pop();
    printStatus(minStack1, "pop()");
    std::cout << std::endl;
    // --- 测试用例 2: 最小值弹出测试 ---
    // 这个用例的关键是，当最小的元素被弹出后，第二小的值能否成为新的最小值
    std::cout << "=========== 测试用例 2: 最小值弹出 ===========" << std::endl;
    MinStack minStack2;
    minStack2.push(5);
    printStatus(minStack2, "push(5)");
    minStack2.push(3);
    printStatus(minStack2, "push(3)");
    minStack2.push(4);
    printStatus(minStack2, "push(4)");
    minStack2.push(1); // 新的最小值
    printStatus(minStack2, "push(1)");
    minStack2.push(2);
    printStatus(minStack2, "push(2)");

    minStack2.pop(); // 弹出 2
    printStatus(minStack2, "pop()");

    minStack2.pop();                                 // 弹出 1 (之前的最小值)
    printStatus(minStack2, "pop() [弹出了最小值1]"); // 此时最小值应该变回 3
    std::cout << std::endl;

    // --- 测试用例 3: 重复最小值测试 ---
    // 这个用例测试当栈中有多个相同的最小值时，弹出一个后，最小值是否改变
    std::cout << "=========== 测试用例 3: 重复最小值 ===========" << std::endl;
    MinStack minStack3;
    minStack3.push(10);
    printStatus(minStack3, "push(10)");
    minStack3.push(5);
    printStatus(minStack3, "push(5)");
    minStack3.push(5); // 重复的最小值
    printStatus(minStack3, "push(5)");
    minStack3.push(7);
    printStatus(minStack3, "push(7)");

    minStack3.pop(); // 弹出 7
    printStatus(minStack3, "pop()");

    minStack3.pop();                                     // 弹出 5 (一个最小值)
    printStatus(minStack3, "pop() [弹出了一个最小值5]"); // 最小值应该仍然是 5

    minStack3.pop();                                         // 再次弹出 5 (最后一个最小值)
    printStatus(minStack3, "pop() [弹出了最后一个最小值5]"); // 最小值应该变回 10
    std::cout << std::endl;

    // --- 测试用例 4: 数值降序压栈 ---
    // 这种情况下，每次压栈都会更新最小值
    std::cout << "=========== 测试用例 4: 降序压栈 ===========" << std::endl;
    MinStack minStack4;
    minStack4.push(10);
    printStatus(minStack4, "push(10)");
    minStack4.push(5);
    printStatus(minStack4, "push(5)");
    minStack4.push(0);
    printStatus(minStack4, "push(0)");
    minStack4.push(-5);
    printStatus(minStack4, "push(-5)");
    std::cout << std::endl;

    // --- 测试用例 5: 全部弹出 ---
    // 测试栈被完全清空的情况
    std::cout << "=========== 测试用例 5: 全部弹出 ===========" << std::endl;
    MinStack minStack5;
    minStack5.push(1);
    minStack5.push(2);
    printStatus(minStack5, "push(2)");
    minStack5.pop();
    printStatus(minStack5, "pop()");
    minStack5.pop();
    printStatus(minStack5, "pop()"); // 栈现在应该是空的

    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */