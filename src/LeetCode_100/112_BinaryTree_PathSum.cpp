#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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
};

class Solution2 {
public:
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
};