/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int maxFre = 0;          // 最大频率
    int fre = 0;             // 当前频率
    TreeNode *pre = nullptr; // 上一个节点
    vector<int> ans;
    void dfs(TreeNode *cur)
    {
        if (cur == nullptr)
            return;
        dfs(cur->left);
        if (pre == nullptr)
        {
            pre = cur;
            fre = 1;
        }
        else
        {
            if (cur->val == pre->val)

                fre++;
            else
                fre = 1;
            pre = cur;
        }
        if (fre < maxFre)
        {
        }
        if (fre == maxFre)
            ans.push_back(cur->val);
        if (fre > maxFre)
        {
            maxFre = fre;
            ans.clear();
            ans.push_back(cur->val);
        }
        dfs(cur->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
// @lc code=end
