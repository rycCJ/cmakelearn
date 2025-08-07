#include <iostream>
#include <stack>

#include <cctype>
#include <string>
//  using namespace std;
class Solution
{

public:
    std::string decodeString(std::string s)
    {
        std::stack<int> countStack;
        std::stack<std::string> stringStack;

        std::string currentString = "";
        int currentNum = 0;
        for (char c : s)
        {
            if (c == '[')
            {
                stringStack.push(currentString);
                countStack.push(currentNum);

                currentString = "";
                currentNum = 0;
            }
            else if (c == ']')
            {
                int k = countStack.top();
                countStack.pop();
                std::string prevString = stringStack.top();
                stringStack.pop();
                // std::string segmentToRepeat = currentString;
                std::string repeatedSegment = "";
                for (int i = 0; i < k; ++i)
                {
                    repeatedSegment += currentString;
                }
                currentString = prevString + repeatedSegment;
            }
            else if (isdigit(c))
            {
                currentNum = currentNum * 10 + (c - '0'); // 秒不绝伦
            }
            else if (isalpha(c))
            {
                currentString += c;
            }
        }
        return currentString;
    }
};

int main()
{
    Solution solution;
    solution.decodeString("3[a2[c]]");
    std::cout << solution.decodeString("3[a2[c]]") << std::endl;
}