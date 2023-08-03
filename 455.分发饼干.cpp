/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
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
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int start = 0;
        int count = 0;
        for (auto gg : g)
        {
            for (int i = start; i < s.size(); i++)
            {
                if (gg <= s[i])
                {
                    count++;
                    start = i + 1;
                    break;
                }
            }
        }
        return count;
    }
};
// @lc code=end