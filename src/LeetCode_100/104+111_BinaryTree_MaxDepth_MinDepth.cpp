#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
// Definition for a binary tree node.
// https://pythontutor.com/render.html#mode=display 图形化界面
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
  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int ldepth = maxDepth(root->left);
    int rdepth = maxDepth(root->right);

    int depth = max(ldepth, rdepth) + 1;
    return depth;
  }
  // BFS方法
  int maxDepth2(TreeNode *root) {
    // TreeNode *cur = root;
    queue<TreeNode *> q;
    int depth = 0;
    if (root == nullptr)
      return 0;
    q.push(root);

    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      depth++;
    }
    return depth;
  }
  // /*-------------DFS 使用-------------*/
  /*------------递归方法-------------*/
  int minDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int ldepth = minDepth(root->left);
    int rdepth = minDepth(root->right);
    if (root->right == nullptr) {
      return ldepth + 1;
    }
    if (root->left == nullptr) {
      return rdepth + 1;
    }
    return min(ldepth, rdepth) + 1;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
