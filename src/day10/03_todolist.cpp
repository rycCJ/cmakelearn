#include<vector>
#include<iostream>
#include<string>
#include <limits>   // 需要这个头文件来使用 std::numeric_limits
#include "my_pro_project/todolist.hpp"  // 包含自定义的头文件
/**
 * @file day4_todo_list.cpp
 * @brief 一个简单的待办事项列表应用，用于练习 std::vector 和 std::string。
 *
 * ====================================================================
 * 功能挑战
 * ====================================================================
 * 编写一个C++程序，实现一个命令行“待办事项 (To-Do) 列表”。
 *
 * 具体任务：
 * 1. 使用 `std::vector<std::string>` 来存储所有的待办事项。
 * 2. 程序需要提供一个循环菜单，包含以下选项：
 * - 添加任务 (Add)
 * - 查看任务 (View)
 * - 删除任务 (Delete)
 * - 退出 (Quit)
 * 3. **添加任务**: 提示用户输入任务描述（一个字符串），然后将其添加到
 * vector 的末尾。
 * 4. **查看任务**:
 * - 如果列表为空，打印 "待办事项列表为空。"
 * - 否则，遍历 vector，并以带编号的列表形式打印所有任务，例如：
 * 1. 学习 C++
 * 2. 编写代码
 * 5. **删除任务**:
 * - 先调用“查看任务”的功能，让用户看到所有任务及其编号。
 * - 如果列表为空，则提示无法删除。
 * - 提示用户输入要删除的任务编号。
 * - **验证输入**: 确保用户输入的编号是有效的（例如，在 1 和任务总数之间）。
 * - 如果输入有效，从 vector 中删除对应的任务。 (提示: vector 的 `erase` 方法)
 * 6. **退出**: 结束程序。
 * ====================================================================
 *
 * 知识点:
 * - `std::vector` 的声明、添加元素 (`push_back`)、获取大小 (`size`)、
 * 删除元素 (`erase`)、访问元素 (`at` 或 `[]`)。
 * - `std::string` 的使用，特别是通过 `std::getline` 读取带空格的输入。
 * - 循环和 `switch` 语句来构建交互式菜单。
 * - 输入验证。
 */

 int main()
 {
    std::vector<std::string> myvector;

    std::string strs;
    int choice;

    do{

        Menu();
        std::cout << "Do choose!" << std::endl;
        std::cin >> choice;
        // 检查输入是否为有效数字
        if (std::cin.fail()) {
            std::cout << "Please Input Number \n";
            std::cin.clear(); // 清除错误状态
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }

        switch (choice)
        {
        case 1:
            Add(myvector);            
            break;
        case 2:
            View(myvector);         
            break;  
        case 3:
            Delete(myvector);            
            break;    
        case 4:
            std::cout << "----------Wating to quit...----------" << std::endl;
                 
            break;  
        default:
            std::cout << "Wrong!,Please choose again" << std::endl;
            break;
        }

    }while(choice != 4);

    std::cout << "-----------------------------" << std::endl;  
    std::cout << "--------------Bye------------" << std::endl;
    std::cout << "-----------------------------" << std::endl; 


 }


/*Delete 函数错误较多*/


/*
程序要求用户输入一个数字 choice：
但用户没有输入数字，而是输入了一个字母，比如 a，然后按下了回车。这时，std::cin 就“生病”了：
进入错误状态：因为它想要一个数字却得到了一个字母，std::cin 会设置一个内部的错误标志（failbit）。在此状态下，它会拒绝所有后续的读取请求。

留下“垃圾”：那个错误的输入 a 以及你按下的回车符 \n，依然残留在输入缓冲区（input buffer）里。

std::cin.clear() 和 std::cin.ignore() 就是用来解决这两个问题的“特效药”。

std::cin.clear();

“cin，我知道你出错了，现在我把你的错误状态清除了，你恢复正常吧。”

std::cin.ignore(...)

“cin，现在把你缓冲区里所有没用的东西，直到下一个回车符为止，全部扔掉。”
*/


 




/*

//迭代访问
std::vector<int> myVector; // 创建一个存储整数的空 vector

for (auto it = myVector.begin(); it != myVector.end(); ++it) {                 //这个函数返回的迭代器并不指向最后一个元素，而是指向一个理论上存在于最后一个元素之后的位置。它就像一个“终点线”或“哨兵”，标志着向量的结束。

   std::cout << *it << " ";}          // 是解引用 (dereference) 操作符。当迭代器 it 指向某个元素时，*it 会获取存储在该位置的实际值。

创建一个迭代器 it，指向向量的第一个元素。

检查 it 是不是已经到达了终点。不是。

打印出 it 指向的第一个元素的值。

将 it 移动到下一个元素。

检查 it 是不是已经到达了终点。不是。

打印出 it 指向的第二个元素的值。

...这个过程一直重复，直到 it 遍历完所有元素，最终指向了 myVector.end() 所代表的“终点线”位置。

此时，循环条件 it != myVector.end() 为 false，循环结束。

*/



