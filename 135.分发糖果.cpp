/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
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
    int candy(vector<int> &ratings)
    {
        int ans = 0;
        vector<int> candys(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                candys[i] = candys[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && candys[i] <= candys[i + 1])
            {
                candys[i] = candys[i + 1] + 1;
            }
        }
        int sum = 0;
        for (int x : candys)
        {
            sum += x;
        }

        return sum;
    }
};
// @lc code=end
