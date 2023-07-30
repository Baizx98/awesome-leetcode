/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    TreeNode *pre = nullptr;
    int ans = INT_MAX;
    void dfs(TreeNode *cur)
    {
        if (cur == nullptr)
            return;
        dfs(cur->left);
        if (pre == nullptr) // 说明此时树最左边的节点是根节点
            pre = cur;
        else
        {
            ans = min(ans, cur->val - pre->val);
            pre = cur;
        }
        dfs(cur->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
// @lc code=end
