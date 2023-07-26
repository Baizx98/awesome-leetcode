/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    void postorder(TreeNode *root, vector<int> &vec)
    {
        if (root == nullptr)
        {
            return;
        }
        postorder(root->left, vec);
        postorder(root->right, vec);
        vec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        // vector<int> ans;
        // postorder(root, ans);
        // return ans;
        // 先序遍历是 中左右，后序遍历时左右中 先序遍历调换一下顺序就是中右左，再反转一下就是左右中了
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
            if (node->left)
                s.push(node->left);
            if (node->right)
                s.push(node->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
