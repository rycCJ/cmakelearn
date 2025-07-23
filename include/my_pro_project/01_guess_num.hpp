#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>

void Play_game(void)
    {
        int secret_num,random_num,input_num;
        std::vector<int> numbers;      //定义一个容器，存储输入的数字，以便计算输入历史次数
    
        srand(time(0));
        random_num = rand();
        secret_num = 1 + random_num % 100;
        std::cout << "-------start game----------" << std::endl;
        std::cout << "-------please input a number----------" << std::endl;
        std::cin >> input_num;
        do
        {
    
            numbers.push_back(input_num);           //将输入的数字存储在容器里面
            if(input_num > secret_num)
            {
                std::cout << "-------too high----------" << std::endl;
            }else
            {
                std::cout << "-------too low----------" << std::endl; 
    
            }
            std::cout << "-------please input a number----------" << std::endl;
            std::cin >> input_num;
    
        } while (input_num != secret_num);
        std::cout << "-------Congratulations--------" << std::endl;
        numbers.push_back(input_num);
        std::cout << "You have tried " << numbers.size() << " times" << std::endl;
    
        //输出numbers元素
        std::cout << "elements:" ;
    
        for(int i = 0;i<numbers.size();i++)
        {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "-------GAME OVER--------" << std::endl;
    }
    