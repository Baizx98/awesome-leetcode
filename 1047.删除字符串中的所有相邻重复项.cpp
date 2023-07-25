/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
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
    string removeDuplicates(string s)
    {
        stack<char> q;
        for (auto &ch : s)
        {
            if (q.empty())
                q.push(ch);
            else
            {
                if (q.top() == ch)
                    q.pop();
                else
                    q.push(ch);
            }
        }
        string ans;
        while (!q.empty())
        {
            ans = q.top() + ans;
            q.pop();
        }
        return ans;
    }
};
// @lc code=end
