#include<vector>
#include<iostream>
#include<string>
#include <limits> 

void Menu(void)
{
    std::cout << "---------Menu-----------" << std::endl;
    std::cout << "---------1. Add-----------" << std::endl;
    std::cout << "---------2. View-----------" << std::endl;
    std::cout << "---------3. Delete-----------" << std::endl;
    std::cout << "---------4. quit-----------" << std::endl;
}

void Add(std::vector<std::string>& tasks)
{
    std::cout << "Input the task:" << std::endl; 
    std::string new_task;
    // cin.ignore() 清除之前输入 choice 后留下的换行符
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    std::getline(std::cin,new_task);    //std::cin >> strs;。这个语句在遇到空格时就会停止读取。所以，如果用户想输入一个任务 "Buy milk"，程序只会读取到 "Buy"。

    tasks.push_back(new_task);
    std::cout << "Task has been added!" << std::endl; 

}

void View(const std::vector<std::string>& tasks)
{
    if (tasks.empty())
    {
        std::cout << "task is empty" << std::endl;    
        
    }
    else
    {
        std::cout << "------------task----------" << "\n" ;
        for(int it = 0;it < tasks.size(); ++it){
            std::cout << it+1 << "." << tasks[it] << "\n" ;                     
        }
        std::cout << std::endl;
    }    
}

void Delete(std::vector<std::string>& tasks)
{
    if(tasks.empty())
    {
        std::cout << "task is empty" << std::endl;        
        return;
    }
    int number;
    View(tasks);
    std::cout << "choose to the deleted number:" << std::endl;  
    std::cin >> number;
    if(std::cin.fail() || number > static_cast<int>(tasks.size()) || number < 1)   // task_number 是一个 int 类型（有符号整数）。    tasks.size()是一个 size_t 类型（无符号整数）。
//static_cast 是 C++ 中用于进行类型转换的一种标准、安全的方式。它告诉编译器：“我明确知道我想把括号里的东西转换成 < > 里的类型”。通过使用 static_cast<int>(tasks.size())，我们明确地将 tasks.size() 的结果从无符号的 size_t 转换成了有符号的 int。这样一来，比较的两边就都是 int 类型了，编译器就不会再有任何困惑或警告。

    {
        std::cout << "Wrong!" << std::endl;

        if(std::cin.fail()){
            std::cin.clear();  // 清除错误状态
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');// 忽略错误输入
        }
        return;   //立即返回，不再执行后面的代码
    }
    tasks.erase(tasks.begin()+number-1);          //*  number-1:比如向删除第一个元素，输入1后为：1-1=0，则迭代器移动0位，仍然指向第一个元素。
  //    tasks.begin();    本身只是给你一个“起点”，但通过和算术运算结合，它能让你精确定位到 vector 中的任何一个元素，从而进行访问、修改或删除等操作。
    std::cout << "task " << number << " have been deleted!\n";
  //显示修改后的任务
    std::cout << "after delete:" ;
    View(tasks);
}
