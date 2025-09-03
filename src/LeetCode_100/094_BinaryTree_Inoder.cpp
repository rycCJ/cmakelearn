#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
// 测试需要
#include <optional>
#include <cassert>
#include <random>

using namespace std;
// Definition for a binary tree node.
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
    /*-------------------------------迭代实现--------------------

    一直往左走，把节点压栈；

    弹出一个节点，访问它；

    转向它的右孩子，继续循环。*/
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return {};
        stack<TreeNode *> next;
        // vector<TreeNode *> cur = {root};
        TreeNode *cur = root;
        while (cur != nullptr || !next.empty())
        {
            while (cur != nullptr)
            {
                next.push(cur);
                cur = cur->left;
            }
            cur = next.top();
            next.pop();
            ans.push_back(cur->val);
            cur = cur->right;
            // ans.push_back(next.top()->val);
            // next.pop();
            // if (!next.empty())
            // {
            //     cur = next.top()->right;
            //     ans.push_back(next.top()->val);
            // }
        }
        return ans;
    }
};

/*-------------测试用例---------------*/
// 打印 vector
void printVector(const vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    Solution sol;

    // 1. 空树
    cout << "Test 1 (空树): ";
    printVector(sol.inorderTraversal(nullptr)); // 预期: 空

    // 2. 单节点树
    cout << "Test 2 (单节点): ";
    TreeNode *t2 = new TreeNode(1);
    printVector(sol.inorderTraversal(t2)); // 预期: 1
    delete t2;

    // 3. 只有左子树
    cout << "Test 3 (只有左子树): ";
    TreeNode *t3 = new TreeNode(2, new TreeNode(1), nullptr);
    printVector(sol.inorderTraversal(t3)); // 预期: 1 2
    delete t3->left;
    delete t3;

    // 4. 只有右子树
    cout << "Test 4 (只有右子树): ";
    TreeNode *t4 = new TreeNode(1, nullptr, new TreeNode(2));
    printVector(sol.inorderTraversal(t4)); // 预期: 1 2
    delete t4->right;
    delete t4;

    // 5. 完全二叉树: [1,2,3,4,5,6,7]
    cout << "Test 5 (完全二叉树): ";
    TreeNode *t5 = new TreeNode(1);
    t5->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    t5->right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
    printVector(sol.inorderTraversal(t5)); // 预期: 4 2 5 1 6 3 7
    delete t5->left->left;
    delete t5->left->right;
    delete t5->left;
    delete t5->right->left;
    delete t5->right->right;
    delete t5->right;
    delete t5;

    // 6. 普通不平衡树: [1,null,2,3]
    cout << "Test 6 (不平衡树): ";
    TreeNode *t6 = new TreeNode(1);
    t6->right = new TreeNode(2, new TreeNode(3), nullptr);
    printVector(sol.inorderTraversal(t6)); // 预期: 1 3 2
    delete t6->right->left;
    delete t6->right;
    delete t6;

    return 0;
}