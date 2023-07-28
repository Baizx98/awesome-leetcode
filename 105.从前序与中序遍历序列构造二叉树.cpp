/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    int pre_idx;
    unordered_map<int, int> idx_map;
    TreeNode *helper(int in_left, int in_right, vector<int> &preorder, vector<int> inorder)
    {
        if (in_left > in_right)
            return nullptr;
        int root_val = preorder[pre_idx];
        TreeNode *root = new TreeNode(root_val);
        int index = idx_map[root_val];
        pre_idx++;
        root->left = helper(in_left, index - 1, preorder, inorder);
        root->right = helper(index + 1, in_right, preorder, inorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        pre_idx = 0;
        int id = 0;
        for (auto val : inorder)
            idx_map[val] = id++;
        return helper(0, inorder.size() - 1, preorder, inorder);
    }
};
// @lc code=end
