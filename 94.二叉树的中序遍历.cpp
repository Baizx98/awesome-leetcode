/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
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
    // void inorder(TreeNode *root, vector<int> &vec)
    // {
    //     if (root == nullptr)
    //     {
    //         return;
    //     }
    //     inorder(root->left, vec);
    //     vec.push_back(root->val);

    //     inorder(root->right, vec);
    // }
    vector<int> inorderTraversal(TreeNode *root)
    {
        // vector<int> ans;
        // inorder(root, ans);
        // return ans;
        // 迭代法 ，找左孩子找到底，然后找到一个右孩子就再把这个节点的左孩子找到底
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (cur != nullptr || !s.empty())
        {
            if (cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = s.top(); // 最底下的左孩子
                s.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end
