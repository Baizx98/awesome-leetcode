/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traversal(TreeNode *cur, string path, vector<string> &ans)
    {

        path += to_string(cur->val);
        if (cur->left == nullptr && cur->right == nullptr)
        {
            ans.push_back(path);
            return;
        }
        // 实际上这两个if判断就保证了每层递归中的cur都不是空指针
        if (cur->left)
        {
            traversal(cur->left, path + "->", ans);
        }
        if (cur->right)
        {
            traversal(cur->right, path + "->", ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string path;
        if (root == nullptr)
            return ans;
        traversal(root, path, ans);
        return ans;
    }
};
// @lc code=end
