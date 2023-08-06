/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
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
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
        //      { return a[1] < b[1]; });
        // int ans = 0;
        // for (int i = 0; i < points.size();)
        // {
        //     int minRight = points[i][1];
        //     i++;
        //     while (i < points.size() && points[i][0] <= minRight)
        //     {
        //         i++;
        //     }
        //     // 此时找到的i就是下一箭要射的气球了，此时的poinst[i]的右端就是剩余气球的最左边的右端了
        //     ans++;
        // }
        // return ans;
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        int result = 1; // points 不为空至少需要一支箭
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > points[i - 1][1])
            {             // 气球i和气球i-1不挨着，注意这里不是>=
                result++; // 需要一支箭
            }
            else
            {                                                       // 气球i和气球i-1挨着
                points[i][1] = min(points[i - 1][1], points[i][1]); // 更新重叠气球最小右边界
            }
        }
        return result;
    }
};
// @lc code=end
