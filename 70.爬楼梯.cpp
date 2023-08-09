/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[2];
        dp[0] = 1;
        dp[1] = 2;
        if (n < 3)
        {
            return dp[n - 1];
        }
        int ans = 0;
        for (int i = 3; i <= n; i++)
        {
            ans = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = ans;
        }
        return ans;
    }
};
// @lc code=end
