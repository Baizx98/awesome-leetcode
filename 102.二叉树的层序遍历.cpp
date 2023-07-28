/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    void order(TreeNode *cur, vector<vector<int>> &ans, int depth)
    {
        if (cur == nullptr)
        {
            return;
        }
        if (ans.size() == depth)
        {
            ans.push_back(vector<int>());
        }
        ans[depth].push_back(cur->val);
        order(cur->left, ans, depth + 1);
        order(cur->right, ans, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // queue<TreeNode *> q;
        // vector<vector<int>> ans;
        // // 预处理 先将根节点入队
        // if (root != nullptr)
        // {
        //     q.push(root);
        // }

        // while (!q.empty())
        // {
        //     int size = q.size(); // 队列长度，也就是当前层的节点个数，第一层的节点数一定为1
        //     vector<int> temp;
        //     for (int i = 0; i < size; i++)
        //     {
        //         if (q.front()->left)
        //             q.push(q.front()->left);
        //         if (q.front()->right)
        //             q.push(q.front()->right);
        //         temp.push_back(q.front()->val);
        //         q.pop();
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;

        vector<vector<int>> ans;
        int depth = 0;
        order(root, ans, depth);
        return ans;
    }
};
// @lc code=end
