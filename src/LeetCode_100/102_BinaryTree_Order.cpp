#include <iostream>
#include <queue>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;
        vector<vector<int>> ans;
        while (!q.empty())
        {
            vector<int> vals;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                vals.push_back(cur->val);
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
            ans.push_back(vals);
            // ans,emplace_back(vals);
        }
        return ans;
    }
};

/* ---------------------- 测试辅助 ---------------------- */

// 由堆式数组（层序，null 用 nullopt）构造二叉树
TreeNode *buildTree(const vector<optional<int>> &a)
{
    if (a.empty() || !a[0].has_value())
        return nullptr;
    vector<TreeNode *> nodes(a.size(), nullptr);
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i].has_value())
            nodes[i] = new TreeNode(*a[i]);
    }
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (!nodes[i])
            continue;
        size_t li = 2 * i + 1, ri = 2 * i + 2;
        if (li < a.size())
            nodes[i]->left = nodes[li];
        if (ri < a.size())
            nodes[i]->right = nodes[ri];
    }
    return nodes[0];
}

// 释放整棵树
void freeTree(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *t = q.front();
        q.pop();
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
        delete t;
    }
}

// 把二维结果转成字符串，便于报错时查看
string toStr(const vector<vector<int>> &vv)
{
    string s = "[";
    for (size_t i = 0; i < vv.size(); ++i)
    {
        s += "[";
        for (size_t j = 0; j < vv[i].size(); ++j)
        {
            s += to_string(vv[i][j]);
            if (j + 1 < vv[i].size())
                s += ",";
        }
        s += "]";
        if (i + 1 < vv.size())
            s += ",";
    }
    s += "]";
    return s;
}

// 参考实现：按深度递归收集（与队列 BFS 思路不同，用于交叉验证）
int height(TreeNode *r)
{
    if (!r)
        return 0;
    return 1 + max(height(r->left), height(r->right));
}
void collectAtDepth(TreeNode *r, int d, vector<int> &out)
{
    if (!r)
        return;
    if (d == 0)
    {
        out.push_back(r->val);
        return;
    }
    collectAtDepth(r->left, d - 1, out);
    collectAtDepth(r->right, d - 1, out);
}
vector<vector<int>> referenceLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    int h = height(root);
    for (int d = 0; d < h; ++d)
    {
        vector<int> level;
        collectAtDepth(root, d, level);
        res.push_back(move(level));
    }
    return res;
}

// 单例用例运行与断言
void runCase(const vector<optional<int>> &arr, const string &name)
{
    TreeNode *root = buildTree(arr);
    Solution sol;
    auto got = sol.levelOrder(root);
    auto exp = referenceLevelOrder(root);
    if (got != exp)
    {
        cerr << "FAILED: " << name << "\nexpected: " << toStr(exp)
             << "\n   got : " << toStr(got) << endl;
        assert(false);
    }
    else
    {
        cout << "PASSED: " << name << " -> " << toStr(got) << endl;
    }
    freeTree(root);
}

// 随机生成一棵树（节点值在 [-50,50]），控制规模与空子树概率
TreeNode *genRandomTree(int maxNodes, double nullProb, mt19937 &rng)
{
    uniform_int_distribution<int> val(-50, 50);
    uniform_real_distribution<double> prob(0.0, 1.0);
    if (maxNodes <= 0)
        return nullptr;

    // 用队列逐层扩展
    TreeNode *root = new TreeNode(val(rng));
    int count = 1;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty() && count < maxNodes)
    {
        TreeNode *cur = q.front();
        q.pop();
        // 左
        if (count < maxNodes && prob(rng) > nullProb)
        {
            cur->left = new TreeNode(val(rng));
            q.push(cur->left);
            ++count;
        }
        // 右
        if (count < maxNodes && prob(rng) > nullProb)
        {
            cur->right = new TreeNode(val(rng));
            q.push(cur->right);
            ++count;
        }
    }
    return root;
}
void runRandom(int cases, int maxNodes, double nullProb, uint32_t seed)
{
    mt19937 rng(seed);
    Solution sol;
    for (int i = 1; i <= cases; ++i)
    {
        TreeNode *root = genRandomTree(maxNodes, nullProb, rng);
        auto got = sol.levelOrder(root);
        auto exp = referenceLevelOrder(root);
        if (got != exp)
        {
            cerr << "FAILED: RandomCase#" << i << "\nexpected: " << toStr(exp)
                 << "\n   got : " << toStr(got) << endl;
            assert(false);
        }
        freeTree(root);
    }
    cout << "PASSED: " << cases << " random cases" << endl;
}

/* ---------------------- 主函数：全面测试 ---------------------- */
int main()
{
    // 1) 空树
    runCase({}, "Empty tree");

    // 2) 单节点
    runCase({1}, "Single node");

    // 3) 两层满二叉树
    runCase({1, 2, 3}, "Perfect 2-level");

    // 4) 三层完全二叉树（最后一层缺一个中间位置）
    runCase({1, 2, 3, 4, 5, nullopt, 7}, "Complete with a missing node");

    // 5) 只有左链
    runCase({1, 2, nullopt, 3, nullopt, 4}, "Left-skewed chain");

    // 6) 只有右链
    runCase({1, nullopt, 2, nullopt, 3, nullopt, 4}, "Right-skewed chain");

    // 7) 强不平衡混合结构
    runCase({1, 2, nullopt, 3, 4, nullopt, nullopt, 5}, "Unbalanced mixed");

    // 8) 含负数与重复值
    runCase({1, -2, -2, nullopt, 3, 3, nullopt}, "Negatives & duplicates");

    // 9) 大一点的满二叉树（值按层序 1..7）
    runCase({1, 2, 3, 4, 5, 6, 7}, "Perfect 3-level");

    // 10) 随机压力测试（可调次数/规模/空子树概率/随机种子）
    runRandom(/*cases=*/50, /*maxNodes=*/60, /*nullProb=*/0.35, /*seed=*/20250819);

    cout << "\nALL TESTS PASSED ✅" << endl;
    return 0;
}