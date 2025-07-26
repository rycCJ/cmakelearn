#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>
/*示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

解释：

在 strs 中没有字符串可以通过重新排列来形成 "bat"。
字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
*/
// using namespace std
class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> map;
        std::vector<std::vector<std::string>> vector1;
        int j = 0;
        for (int i = 0; i < strs.size(); ++i)
        {
            std::string tem = strs[i];
            std::sort(tem.begin(), tem.end()); // tem是一个排序后的字符串，用于作为键
            map[tem].push_back(strs[i]);
        }
        for (std::unordered_map<std::string, std::vector<std::string>>::iterator it = map.begin(); it != map.end(); ++it)
        {
            vector1.push_back(it->second); // 将map中的值添加到vector1中
        }
        return vector1;
    }
};

int main()
{
    Solution solution;
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    solution.groupAnagrams(input);
}