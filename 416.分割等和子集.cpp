/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
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
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto x : nums)
            sum += x;
        vector<int> dp(100001, 0);
        if (sum % 2 == 1)
            return false;
        int target = sum / 2; // target代表背包中的数字的总和
        // 也就是说能不能从nums中找到一组数，这些数的和等于总和的一半
        // 对应到01背包问题，也就是找到当背包容量为target时，其中物品的价值总和是不是target
        for (int i = 0; i < nums.size(); i++)
        {                                           // 先遍历物品
            for (int j = target; j >= nums[i]; j--) // j代表背包容量，如果背包容量小于当前物品，该物品就无法放入
            {
                // 再遍历背包容量
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
