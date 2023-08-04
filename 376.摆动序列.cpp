/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
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
    int wiggleMaxLength(vector<int> &nums)
    {
        // 特例判断
        if (nums.size() == 1)
            return 1;
        int ans = 1;
        // 如果之前是上坡，令direction=1，下坡为-1
        int direction = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                continue; // 平坡，不处理
            else if (nums[i] > nums[i - 1])
            {
                if (direction == 1)
                    continue;
                direction = 1;
                ans++;
            }
            else
            {
                if (direction == -1)
                    continue;
                direction = -1;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
