#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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
class Solution {
public:
    /*
    第一步：如果数组大小为零的话，说明是空节点了。

    第二步：如果不为空，那么取后序数组最后一个元素作为节点元素。

    第三步：找到后序数组最后一个元素在中序数组的位置，作为切割点

    第四步：切割中序数组，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）

    第五步：切割后序数组，切成后序左数组和后序右数组

    第六步：递归处理左区间和右区间
    */
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    
    if (inorder.size() == 0) {
      return nullptr;
    }
    int value = postorder.back();
    TreeNode *node = new TreeNode(value);
    int i;
    for(i = 0;i < inorder.size();i++) {
      if (inorder[i] == value)
        break;
    }
//注意找不到的情况
            // 校验：如果没找到根节点（输入不合法）
        if (i == inorder.size()) {
            return nullptr; // 或根据需求处理错误
        }
  

    // vector<int> in_right;
    // int size = inorder.size()-1-i;
    // for (int n = 0; n < size; i++,n++) {
    //   in_right[n] = inorder[i + 1];
    // }
    // 计算后序右数组

    // vector<int> po_right;
    // for (int n = 0; n < size; n++, i++) {
    //   po_right[n] = postorder[i];
    // }
    //中序左数组
    vector<int> in_left(inorder.begin(),inorder.begin()+i);
    //后续的左数组
    vector<int> po_left(postorder.begin(),postorder.begin()+i);
  // 计算中序右数组
    vector<int> in_right(inorder.begin() + i + 1, inorder.end());
    vector<int> po_right(postorder.begin() +  in_left.size(), postorder.end()-1 );

    node->left = buildTree(in_left, po_left);//中序左数组 后续的左数组
    node->right=  buildTree(in_right,po_right);//中序右数组 后续的右数组
     return node;   
    }
};
int main() {
  
}