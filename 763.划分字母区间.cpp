/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
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
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> pos;
        for (int i = 0; i < s.length(); i++)
        {
            pos[s[i]] = i;
        }
        vector<int> ans;
        int nowPos = 0;
        int point = -1;
        for (int i = 0; i < s.length(); i++)
        {
            nowPos = max(pos[s[i]], nowPos);
            if (i == nowPos)
            {
                ans.push_back(i - point);
                nowPos = 0;
                point = i;
            }
        }
        return ans;
    }
};
// @lc code=end
