/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
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
    void dfs(int cur, vector<int> &nums)
    {
        if (cur == nums.size())
        {
            ans.push_back(set);
            return;
        }
        // 当前元素加入，递归下一个
        set.push_back(nums[cur]);
        dfs(cur + 1, nums);
        set.pop_back();
        // 当前元素弹出，递归下一个
        dfs(cur + 1, nums);
    }
    void backtrack(int cur, vector<int> &nums)
    {
        ans.push_back(set);
        if (cur >= nums.size())
            return;

        for (int i = cur; i < nums.size(); i++)
        {
            set.push_back(nums[i]);
            backtrack(i + 1, nums);
            set.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        // dfs(0, nums);
        ans.clear();
        set.clear();
        backtrack(0, nums);
        return ans;
    }
};
// @lc code=end
