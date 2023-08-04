/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
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
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int index = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] *= -1;
                k--;
                index = i + 1; // 最后一个取反的元素的下标+1，也就是第一个没被取反的元素的下标}
            }
            ans += nums[i];
        }
        // 找到对所有负数取反后的最小非负数的下标,分别考虑原数组全正、全负、有正有负的情况
        if (index > 0 && index < nums.size() && nums[index] > nums[index - 1])
            index = index - 1;
        else if (index == nums.size())
            index = nums.size() - 1;

        if (k % 2 == 1)
            ans -= nums[index] * 2;

        return ans;
    }
};
// @lc code=end
