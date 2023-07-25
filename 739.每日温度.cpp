/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        stack<int> s;
        s.push(0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            if (temperatures[i] <= temperatures[s.top()])
            {
                s.push(i);
            }
            else
            {
                while (!s.empty() && temperatures[i] > temperatures[s.top()])
                {
                    ans[s.top()] = i - s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end
