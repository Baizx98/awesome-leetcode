/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->val == key)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            if (root->right == nullptr)
            {
                return root->left;
            }
            if (root->left == nullptr)
            {
                return root->right;
            }
            // 以下情况是被删节点都有左右孩子的情况
            // 寻找删除节点的后继节点
            TreeNode *successor = root->right;
            while (successor->left)
            {
                successor = successor->left;
            }
            root->right = deleteNode(root->right, successor->val);
            // 上一层递归函数中的根节点的孩子指针指向了本层递归函数的返回值，返回successor就
            // 意味着父节点指向了successor，也就是用successor代替本root
            // successor的左右孩子指针分别指向了root的左右孩子，再让上一层节点指向自己
            successor->right = root->right;
            successor->left = root->left;
            return successor;
        }
        return root;
    }
};
// @lc code=end
