/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <iostream>
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *ans = nullptr;
    bool helper(TreeNode *cur, TreeNode *p, TreeNode *q)
    {
        if (cur == nullptr)
            return false;
        bool left = helper(cur->left, p, q);
        bool right = helper(cur->right, p, q);
        if (ans != nullptr)
            return true;
        if (left && right && (ans == nullptr))
        {
            ans = cur;
            return true;
        }
        if ((left || right) && (cur == q || cur == p) && (ans == nullptr))
        {
            ans = cur;
            return true;
        }
        if (left || right || cur == q || cur == p) // 说明当前节点及其子树中包含目标值
            return true;
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // helper(root, p, q);
        // return ans;
        if (root == q || root == p || root == NULL)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL)
            return root;
        if (left == NULL)
            return right;
        return left;
    }
};
// @lc code=end
