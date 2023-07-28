/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode *root)
    {
        // queue<TreeNode *> q;
        // int depth = 0;
        // if (root != nullptr)
        //     q.push(root);
        // while (!q.empty())
        // {
        //     int size = q.size();
        //     depth++;

        //     for (int i = 0; i < size; i++)
        //     {
        //         if (q.front()->left == nullptr && q.front()->right == nullptr)
        //             return depth;
        //         if (q.front()->left)
        //             q.push(q.front()->left);
        //         if (q.front()->right)
        //             q.push(q.front()->right);
        //         q.pop();
        //     }
        // }
        // return depth;

        // 递归法
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        if (root->left != nullptr && root->right == nullptr)
            return minDepth(root->left) + 1;
        if (root->right != nullptr && root->left == nullptr)
            return minDepth(root->right) + 1;
        // if (root->left != nullptr && root->right != nullptr)
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
// @lc code=end
