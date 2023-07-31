/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
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
    vector<int> temp;
    int sum = 0;
    void backtrack(vector<int> candidates, int target, int start)
    {
        if (sum == target)
        {
            ans.push_back(temp);
            return;
        }
        if (sum > target)
            return;

        for (int i = start; i < candidates.size(); i++)
        {
            sum += candidates[i];
            temp.push_back(candidates[i]);
            backtrack(candidates, target, i);
            sum -= candidates[i];
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtrack(candidates, target, 0);
        return ans;
    }
};
// @lc code=end
