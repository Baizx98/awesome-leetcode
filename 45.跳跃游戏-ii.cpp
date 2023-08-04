/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
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
    int jump(vector<int> &nums)
    {
        int ans = 0;
        int start = 0; // 当前步 起跳位置的范围的左端
        int end = 1;   // 当前步 起跳位置的范围的右端
        while (end < nums.size())
        {
            int maxPos = 0;                   // 当前步落点位置的范围，也是下一步起跳点的范围
            for (int i = start; i < end; i++) // 当前步 起跳点的范围，为了找到当前步落点位置的最大值，作为下一步起跳范围的右端
            {
                maxPos = max(maxPos, i + nums[i]);
            }
            start = end + 1; // 当前步起跳位置的左端=上一步 起跳位置范围的右端+1
            end = maxPos;
            ans++;
        }
        return ans;
    }
};
// @lc code=end
