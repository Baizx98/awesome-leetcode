/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
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
    vector<int> path;
    void backtrack(unordered_set<int> &s, vector<int> &nums)
    {
        if (s.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(i) != s.end())
                continue;
            path.push_back(nums[i]);
            s.insert(i);
            backtrack(s, nums);
            path.pop_back();
            s.erase(i);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        unordered_set<int> s;
        backtrack(s, nums);
        return ans;
    }
};
// @lc code=end
