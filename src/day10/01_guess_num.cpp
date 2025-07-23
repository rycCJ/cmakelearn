/* #include<iostream>
#include"mycpp/sum.h"

// using namespace std;   使用cout  endl时候需要将 std 命名空间的所有内容导入到当前作用域，此时可以直接使用 cout，因为编译器已经知道它来自 std


int main()
{
    std::cout<<sum(1,3);
}*/
/* -----------extern 的使用----------*/
    /*
#include<iostream>
int count;

extern void support(void);
int main()
{
    count = 5;
    support();
}
    */

    /**
 * @file day2_number_guessing_game.cpp
 * @brief 一个经典的数字猜谜游戏，综合运用了控制流知识。
 *
 * ====================================================================
 * 功能挑战
 * ====================================================================
 * 编写一个C++程序，实现一个经典的“数字猜谜游戏”。
 * 程序需要完成以下任务：
 * 1. 在程序内部，自动生成一个介于 1 到 100 之间（包括1和100）的
 * 随机整数作为“秘密数字”。
 * 2. 提示玩家开始游戏，并循环接受玩家的输入作为猜测的数字。
 * 3. 每次猜测后，程序应给出提示：“太高了”、“太低了”或
 * “恭喜你，猜对了！”。
 * 4. 程序需要记录玩家总共尝试了多少次才猜对数字。
 * 5. （选做）程序还应记录玩家每一次猜测的具体数字。
 * 6. 当玩家猜对数字后，游戏结束。此时，程序应显示祝贺信息、
 * 秘密数字、总尝试次数以及（如果实现的话）玩家的所有猜测历史记录。
 * 7. （进阶挑战）游戏结束后，询问玩家是否想“再玩一局？”。如果玩家
 * 输入'y'或'Y'，则开始一轮全新的游戏；否则，程序结束。
 * ====================================================================
 *
 * 知识点:
 * - #include <iostream>, <string>, <vector>, <random>, <ctime>
 * - 控制流: if-else if-else, do-while, for, while
 * - 随机数生成 (std::random_device, std::mt19937, std::uniform_int_distribution)
 * - `std::vector` 的基本使用: 声明，`push_back` 添加元素，范围 `for` 循环遍历。
 * - `break` 和 `continue` 语句的使用。
 */
    /*------------数字猜谜游戏----------*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include "my_pro_project/01_guess_num.hpp" // 包含我们自己的头文件



int main()
{

    char play_again = 'y';
    while(play_again == 'Y' ||play_again == 'y')
    {
        Play_game();
        std::cout << "-------Do you want to play game again?--------" << std::endl;
        std::cin >> play_again;
    }
    std::cout << "-------Thank you for playing,Bye!--------" << std::endl;
}