#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
// #include "my_pro_project/01_guess_num.hpp" 
#include<unordered_map>
/*法一，使用count*/
class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int> hashmap;
            for(int i=0;i<nums.size();i++){
                int result = target - nums[i];
                if(hashmap.count(result))
                {
                    std::cout << "The two numbers are: " << nums[i] << " and " << result << std::endl;
                    std::cout << "Their indices are: " << i << " and " << hashmap[result] << std::endl;
                    return {hashmap[result],i};
                }
            hashmap[nums[i]] = i; // Store the index of the number  first:值  second：键
            }
            return {}; // Return an empty vector if no solution is found
            
        }
    };
/*法二，使用find*/
class Solution2 {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int> hashtable;
            for (int i = 0; i < nums.size(); ++i) {
                auto it = hashtable.find(target - nums[i]);
                if (it != hashtable.end()) {
                    return {it->second, i};
                }
                hashtable[nums[i]] = i;
            }
            return {};
        }
    };

int main(){
    Solution solution;
    std::vector<int> nums = {12,23,9,34,76,3,6,35,44};
    int target = 15;
    solution.twoSum(nums, target);
}