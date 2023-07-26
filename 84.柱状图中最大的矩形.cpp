/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
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
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = 0;
        stack<int> s;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        s.push(0);
        for (int i = 1; i < heights.size(); i++)
        {
            if (heights[i] > heights[s.top()])
            {
                s.push(i);
            }
            else if (heights[i] == heights[s.top()])
            {
                // s.pop();
                s.push(i);
            }
            else
            {
                while (!s.empty() && heights[i] < heights[s.top()])
                {
                    int t = s.top(); // 这是当前要计算的矩形的高度
                    s.pop();
                    if (!s.empty())
                    {
                        ans = max(ans, (i - s.top() - 1) * heights[t]);
                    }
                }
                s.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end
