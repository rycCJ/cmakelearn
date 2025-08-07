#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 构建出来的二叉树是这样的：
//     1
//    / \
//   2   3
//  /   / \
// 4   5   6

// 基本的二叉树节点
// 基本的二叉树节点

// 二叉树的递归遍历框架
void traverse(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    // 前序位置
    traverse(root->left);
    // 中序位置
    traverse(root->right);
    // 后序位置
}

// 修改标准的二叉树遍历框架
void traverseFlip(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    // 反过来，先递归遍历右子树，再递归遍历左子树
    traverseFlip(root->right);
    traverseFlip(root->left);
}

// 层序遍历
void levelOrderTraverse1(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();
        // 访问 cur 节点
        std::cout << cur->val << std::endl;

        // 把 cur 的左右子节点加入队列
        if (cur->left != nullptr)
        {
            q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
        }
    }
}

void levelOrderTraverse2(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    // 记录当前遍历到的层数（根节点视为第 1 层）
    int depth = 1;

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            // 访问 cur 节点，同时知道它所在的层数
            cout << "depth = " << depth << ", val = " << cur->val << endl;

            // 把 cur 的左右子节点加入队列
            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
        }
        depth++;
    }
}
class State
{
public:
    TreeNode *node;
    int depth;

    State(TreeNode *node, int depth) : node(node), depth(depth) {}
};

void levelOrderTraverse3(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<State> q;
    // 根节点的路径权重和是 1
    q.push(State(root, 1));

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();
        // 访问 cur 节点，同时知道它的路径权重和
        cout << "depth = " << cur.depth << ", val = " << cur.node->val << endl;

        // 把 cur 的左右子节点加入队列
        if (cur.node->left != nullptr)
        {
            q.push(State(cur.node->left, cur.depth + 1));
        }
        if (cur.node->right != nullptr)
        {
            q.push(State(cur.node->right, cur.depth + 1));
        }
    }
}

int main()
{
    // 你可以这样构建一棵二叉树：
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    levelOrderTraverse3(root);
}
