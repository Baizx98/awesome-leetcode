/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
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
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i - 1; j++)
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        return dp[n];
    }
};
// @lc code=end
