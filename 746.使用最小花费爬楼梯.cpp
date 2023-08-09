/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
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
    int minCostClimbingStairs(vector<int> &cost)
    {
        int a = 0;
        int b = 0;
        int ans = 0;
        for (int i = 2; i <= cost.size(); i++)
        {
            ans = min(a + cost[i - 2], b + cost[i - 1]);
            a = b;
            b = ans;
        }
        return ans;
    }
};
// @lc code=end
