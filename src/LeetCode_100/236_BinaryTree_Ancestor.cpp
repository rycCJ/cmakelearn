#include <cstddef>
#include <vector>

using namespace std;
// Definition for a binary tree node.
//迭代器:vector<int>  vec(v.begin(),v.end())  表示截取vector<int> v的所有,包含头不包含尾,
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// 236. 二叉树的最近公共祖先

// 子问题返回在子树中是否找到了 p 或 q。

// 当前节点根据左右子树的返回情况做出判断。

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    //        //如果你确定树中所有节点的值唯一（比如二叉搜索树 BST 中常常是这样），那用 root->val == p->val 也可以。
        if (root == nullptr)
            return root;
        if (root == p || root == q)
            return root;
        TreeNode *lAncestor = lowestCommonAncestor(root->left, p, q);

        TreeNode *rAncestor = lowestCommonAncestor(root->right, p, q);

        if (lAncestor ==nullptr&&rAncestor==nullptr)
            return nullptr;
        if (lAncestor != nullptr && rAncestor != nullptr)
            return root;
        if (lAncestor == nullptr && rAncestor != nullptr)
            return rAncestor;   
        return lAncestor;
        
    }
};