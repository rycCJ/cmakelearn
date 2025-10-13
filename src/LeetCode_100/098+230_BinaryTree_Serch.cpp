// 098.验证二叉搜索树
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// 方案 1：中序遍历（推荐的简洁方法）
class Solution {
private:
    // 必须用成员变量或引用参数来维护这个状态
    long long prevVal = LLONG_MIN;

public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        // 1. 递归检查左子树
        if (!isValidBST(root->left)) {
            return false;
        }

        // 2. 检查当前节点（中序遍历的核心逻辑）
        // 核心：当前值必须严格大于上一个值
        if (root->val <= prevVal) {
            return false;
        }

        // 3. 更新上一个值
        prevVal = root->val;

        // 4. 递归检查右子树
        return isValidBST(root->right);
    }
    // 上下限递归（更基础的方法）
    bool isValidBST2(TreeNode* root) {
        return helper(root,LLONG_MIN,LLONG_MAX);
    }
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr)
            return true;
        if (root->val <= lower || root->val >= upper)
            return false;
        bool left = helper(root->left, lower, root->val);
        bool right = helper(root->right, root->val, upper);
        return left && right;
    }
};
// 230. 二叉搜索树中第 K 小的元素

class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        helper(root,result);
        return result[k-1];
    }
    void helper(TreeNode* root, vector<int>& res) {
        if (root == nullptr)
            return;
        helper(root->left,res);
        res.push_back(root->val);
        helper(root->right,res);
    }
};
