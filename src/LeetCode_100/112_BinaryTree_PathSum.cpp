#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;
// Definition for a binary tree node.

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
public:
  // 112. 路径总和
  /*判断该树中是否存在 根节点到叶子节点
   * 的路径，这条路径上所有节点值相加等于目标和 targetSum*/
  
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr)
      return 0;
    targetSum -= root->val;
    if (root->left == nullptr && root->right == nullptr)
      return targetSum == 0;

    bool res1 = hasPathSum(root->left, targetSum);
    bool res2 = hasPathSum(root->right, targetSum);
    return res1 || res2;
  }
  // 129. 求根节点到叶节点数字之和
  
  int totalsum = 0;
  void traverse(TreeNode *node, int currentnum) {
    if (node == nullptr)
      return;
    int parentnum = currentnum * 10 + node->val;
    if (node->left == nullptr && node->right == nullptr) {
      totalsum = totalsum + parentnum;
      return;
    }
    traverse(node->left, parentnum);
    traverse(node->right, parentnum);
  }
  int sumNumbers(TreeNode *root) {

    traverse(root, 0);
    return totalsum;
  }
  // 257. 二叉树的所有路径

  vector<string> getpath(TreeNode *node, string path) {
    vector<string> ans;
    if (node == nullptr)
      return ans;
    path = path+to_string(node->val);
    if (node->left == nullptr && node->right == nullptr)
      {ans.push_back(path);
      return ans;
    }
    path = path + "->";
    vector<string> lpath = getpath(node->left, path);
    vector<string> rpath = getpath(node->right, path);

    ans.insert(ans.end(), lpath.begin(), lpath.end());
        ans.insert(ans.end(), rpath.begin(), rpath.end());
    return ans;
  }



  vector<string> binaryTreePaths(TreeNode *root) {

          return getpath(root, "");
        
    }
  // 113. 路径总和 II

  vector<int> path;
  vector<vector<int>> ans;
  void cacule(TreeNode *root, int currentnum) {
    if (root == nullptr)
      return;
    path.push_back(root->val);
    currentnum-=root->val;
    if (root->left == nullptr && root->right == nullptr){
      if (currentnum == 0) {
        ans.push_back(path);
        path.pop_back();
        return;
      }
      else {
        path.pop_back();
        return;
      }
    }
    cacule(root->left, currentnum);
    cacule(root->right, currentnum);
    path.pop_back();
    return;
    

  }
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    cacule(root, targetSum);
    return ans;
  }

  // 124. 二叉树中的最大路径和

  // 从当前节点向上汇报时，只能选择一条更大的分支继续连接上层。
  //递归，向上汇报？？？？？

int globalmax = numeric_limits<int>::min();
  int cacule2(TreeNode *root) {
    if (root == nullptr)
      return 0;

    int lmax = max(0,cacule2(root->left));
    int rmax = max(0,cacule2(root->right));
    int currentnum = root->val + lmax + rmax;
    globalmax = max(currentnum, globalmax);
    return root->val+max(lmax,rmax);
  }

  int maxPathSum(TreeNode *root) {
    globalmax = numeric_limits<int>::min();
      cacule2(root);
      return globalmax;
    }

};