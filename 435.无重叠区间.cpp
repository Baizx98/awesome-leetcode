/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
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
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int count = 0; // 记录重叠区间的个数，用总区间数减去重叠区间数即为最大不重叠区间数
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= intervals[i - 1][1])
                continue;
            else
            {
                count++;
                intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
            }
        }
        return count;
    }
};
// @lc code=end
