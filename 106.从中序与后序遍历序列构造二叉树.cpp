/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    int post_idx; // 选择后序遍历中post_idx位置的元素作为当前子树的根节点
    unordered_map<int, int> idx_map;
    TreeNode *helper(int in_left, int in_right, vector<int> &inorder, vector<int> &postorder)
    {
        // 如果在中序遍历序列中，左大于右，说明根的一侧已经是空了，也就是没有一侧的子树了
        if (in_left > in_right)
            return nullptr;
        int root_val = postorder[post_idx];      // 从树的根节点的下标拿到根节点的值
        TreeNode *root = new TreeNode(root_val); // 创建根节点
        int index = idx_map[root_val];           // 根据根节点的值找到中序遍历
        post_idx--;
        root->right = helper(index + 1, in_right, inorder, postorder);
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        post_idx = (int)postorder.size() - 1; // 后序遍历的最后一个节点的下标，也就是树的根节点的下标
        int idx = 0;
        for (auto val : inorder)
            idx_map[val] = idx++;
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }
};
// @lc code=end
