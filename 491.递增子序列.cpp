/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
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
// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> sequence;
    void backtrack(int start, vector<int> &nums)
    {
        if (sequence.size() > 1)
        {
            ans.push_back(sequence);
        }
        if (start >= nums.size())
            return;
        unordered_set<int> s;
        for (int i = start; i < nums.size(); i++)
        {
            // 同一层的重复节点要去重，使用set去重
            if ((!sequence.empty() && nums[i] < sequence.back()) || s.find(nums[i]) != s.end())
                continue;
            if (sequence.empty() || nums[i] >= sequence.back())
            {
                s.insert(nums[i]);
                sequence.push_back(nums[i]);
                backtrack(i + 1, nums);
                sequence.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtrack(0, nums);
        return ans;
    }
};
// @lc code=end
