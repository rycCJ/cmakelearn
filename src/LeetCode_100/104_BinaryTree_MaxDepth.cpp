#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// Definition for a binary tree node.
// https://pythontutor.com/render.html#mode=display 图形化界面
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int ldepth = maxDepth(root->left);
        int rdepth = maxDepth(root->right);
        ldepth = ldepth + 1;
        rdepth = rdepth + 1;
        int depth = max(ldepth, rdepth);
        return depth;
    }
};
