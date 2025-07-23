/**
 * @file day3_modular_calculator.cpp
 * @brief 一个使用函数来构建的模块化计算器。
 *
 * ====================================================================
 * 功能挑战
 * ====================================================================
 * 编写一个C++程序，实现一个模块化的计算器。
 * 程序需要遵循“一个函数只做一件事”的原则。
 *
 * 具体任务：
 * 1. 创建一个名为 `display_menu()` 的函数。它的作用是向用户显示
 * 操作选项，例如：1. 加法, 2. 减法, 3. 乘法, 4. 除法, 5. 退出。
 *
 * 2. 为每种数学运算创建一个独立的函数：
 * - `add(double a, double b)`
 * - `subtract(double a, double b)`
 * - `multiply(double a, double b)`
 * - `divide(double a, double b)`
 *
 * 3. `divide()` 函数必须能处理“除数为零”的特殊情况。如果除数为零，
 * 它应该向用户显示错误信息，并返回一个安全的值（例如 0）。
 *
 * 4. 在 `main()` 函数中，实现主逻辑：
 * - 使用一个循环，不断地显示菜单并获取用户选择。
 * - 如果用户选择的是运算操作 (1-4)，则提示用户输入两个数字。
 * - 根据用户的选择，调用相应的运算函数，并打印结果。
 * - 如果用户选择退出 (5)，则结束循环并终止程序。
 * - 需要处理无效的菜单选项。
 * ====================================================================
 *
 * 知识点:
 * - 函数的声明（原型）和定义。
 * - `void` 函数和带返回值的函数。
 * - 参数传递（传值）。
 * - 在 `main` 函数中使用 `switch` 语句调用不同的函数。
 * - 将复杂的程序分解为小的、可管理的函数。
 */
#include<iostream>
#include<cstdlib>
#include "my_pro_project/calculation.hpp" 
#include "my_pro_project/display_menu.hpp" 




int main()
{
    int choice;

    do
    {
        double one,two,result;
        display_menu();
        std::cout << "Do choose!" << std::endl;
        std::cin >> choice;

        if(choice == 5)
        {
            break;
        }

        if(choice < 1 || choice > 5)
        {
            std::cout << "Invalid " << std::endl;
            continue;                                     //有点东西
        }

        std::cout << "Input two numbers!" << std::endl;
        std::cin >> one >> two;

        switch (choice)
        {
        case 1:
            result = add(one,two);
            break;
        case 2:
            result = subtract(one,two);
            break;
        case 3:
            result = multiply(one,two);
            break;
        case 4:
            result = divide(one,two);
            break;
           
        }
        std::cout << "The result is:" << result << std::endl;    
        std::cout << "-----------------------------" << std::endl;  
        
        
    }while (choice != 5);
    std::cout << "-----------------------------" << std::endl;  
    std::cout << "--------------Bye------------" << std::endl;
    std::cout << "-----------------------------" << std::endl;  

}

