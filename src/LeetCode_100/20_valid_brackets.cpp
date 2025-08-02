#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> sta;
        std::unordered_map<char, char> hasmap;
        hasmap = {{')', '('}, {'}', '{'}, {']', '['}};
        for (auto ch : s)
        {
            // 右括号  不执行
            if (hasmap.count(ch))
            {
                if (sta.empty() || sta.top() != hasmap[ch]) // 有无左括号 或者 上一个不是对应的左括号
                    return false;
                sta.pop();
            }
            // 左括号
            else if (ch == '(' || ch == '[' || ch == '{')
            {
                sta.push(ch);
            }
            else
            {
                return false;
            }
        }
        return sta.empty();
    }
};

int main()
{
    Solution sol;
    std::vector<std::string> testCases = {
        "", "(", ")", "([])", "([)]", "{[]}", "{[()()]}", "{[(])}",
        "{{{{{{{{}}}}}}}}", "((((((((((())))))))))", "((()))[]{}",
        "([}}])", "][", "(()", "())",
        std::string(10000, '(') + std::string(10000, ')'), // valid
        std::string(10000, '(')                            // invalid
    };

    for (const auto &s : testCases)
    {
        std::cout << "Input (len=" << s.length() << "): "
                  << (s.length() <= 30 ? "\"" + s + "\"" : "[Too long]")
                  << " => " << (sol.isValid(s) ? "Valid" : "Invalid") << std::endl;
    }

    return 0;
}
