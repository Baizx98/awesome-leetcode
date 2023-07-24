/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
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
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> count12; // 记录两数之和为x的对儿数
        int ans = 0;
        for (int u : nums1)
        {
            for (int v : nums2)
            {
                count12[u + v]++;
            }
        }
        for (int u : nums3)
        {
            for (int v : nums4)
            {
                if (count12.count(-u - v))
                {
                    ans += count12[-u - v];
                }
            }
        }
        return ans;
    }
};
// @lc code=end
