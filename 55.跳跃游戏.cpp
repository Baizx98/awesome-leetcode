/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
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
    bool canJump(vector<int> &nums)
    {
        int cover = 0;
        for (int i = 0; i <= cover; i++)
        {
            if (cover >= nums.size() - 1)
            {
                return true;
            }

            cover = max(cover, nums[i] + i);
        }
        return false;
    }
};
// @lc code=end
