#include <iostream>
#include "my_pro_project/strutils.hpp" // 使用我们的库

int main()
{
    std::cout << "Hello, World!" << std::endl;
    std::string text = "Hello, Modern C++ Project!";

    std::cout << "Original: " << text << std::endl;

    std::string upper = strutils::toUpperCase(text);
    std::cout << "Uppercase: " << upper << std::endl;

    std::string lower = strutils::toLowerCase(text);
    std::cout << "Lowercase: " << lower << std::endl;

    return 0;
}
