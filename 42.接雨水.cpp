/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int sum = 0;
        stack<int> s;
        s.push(0);
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] < height[s.top()])
            {
                s.push(i);
            }
            else if (height[i] == height[s.top()])
            {
                s.pop();
                s.push(i);
            }
            else
            {
                while (!s.empty() && height[i] > height[s.top()])
                {
                    int u = s.top();
                    s.pop();
                    if (!s.empty())
                    {
                        int w = i - s.top() - 1;
                        int h = min(height[s.top()], height[i]) - height[u];
                        sum += w * h;
                    }
                }
                s.push(i);
            }
        }
        return sum;
    }
};
// @lc code=end
