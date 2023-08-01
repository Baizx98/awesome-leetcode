/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
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
    vector<int> set;
    void backtrack(int start, vector<int> &nums)
    {
        ans.push_back(set);

        if (start >= nums.size())
        {
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            set.push_back(nums[i]);
            backtrack(i + 1, nums);
            set.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return ans;
    }
};
// @lc code=end
