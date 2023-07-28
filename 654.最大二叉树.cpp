/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    int maxIdx(vector<int> &nums, int left, int right)
    {
        int index;
        int maxNum = -1;
        for (int i = left; i < right + 1; i++)
        {
            if (nums[i] > maxNum)
            {
                maxNum = nums[i];
                index = i;
            }
        }
        return index;
    }
    TreeNode *helper(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int rootIdx = maxIdx(nums, left, right);
        int rootVal = nums[rootIdx];
        TreeNode *root = new TreeNode(rootVal);
        root->left = helper(nums, left, rootIdx - 1);
        root->right = helper(nums, rootIdx + 1, right);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
