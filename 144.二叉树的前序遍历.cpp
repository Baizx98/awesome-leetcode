/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &vec)
    {
        if (root == nullptr)
        {
            return;
        }
        vec.push_back(root->val);
        preorder(root->left, vec);
        preorder(root->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        // vector<int> ans;
        // preorder(root, ans);
        // return ans;
        // 迭代法 中 先将右孩子入栈，再将左孩子入栈
        stack<TreeNode *> s;
        vector<int> ans;
        if (root == nullptr)
            return {};
        s.push(root);
        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            ans.push_back(node->val);
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
        }
        return ans;
    }
};
// @lc code=end
