/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int ans;
    int traversal(TreeNode *cur)
    {
        // 2代表覆盖，1代表有摄像头，0代表无覆盖
        if (cur == nullptr)
            return 2; // 2代表覆盖
        int left = traversal(cur->left);
        int right = traversal(cur->right);

        // 左右节点都有覆盖
        if (left == 2 && right == 2)
            return 0;

        if (left == 0 || right == 0)
        {
            ans++;
            return 1;
        }
        if (left == 1 || right == 1)
            return 2;
        return -1;
    }
    int minCameraCover(TreeNode *root)
    {
        ans = 0;
        if (traversal(root) == 0)
        {
            ans++;
        }
        return ans;
    }
};
// @lc code=end
