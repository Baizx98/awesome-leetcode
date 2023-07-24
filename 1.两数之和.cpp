/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> ans;
        for (int i = 0; i < nums.size(); i++)
        {

            if (ans.find(nums[i]) != ans.end())
                return {ans.find(nums[i])->second, i};
            ans[target - nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
