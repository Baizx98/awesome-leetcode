/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int rob(TreeNode *root)
    {
        vector<int> dp = robTree(root);
        return max(dp[0], dp[1]);
    }
    vector<int> robTree(TreeNode *cur)
    {
        if (cur == nullptr)
        {
            return {0, 0};
        }
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷当前节点
        int val1 = cur->val + left[0] + right[0];
        // 不偷当前节点
        int val2 = max(left[1], left[0]) + max(right[1], right[0]);
        return {val2, val1};
    }
};
// @lc code=end