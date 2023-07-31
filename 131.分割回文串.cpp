/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <vector>
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
    vector<vector<int>> f;
    vector<vector<string>> ans;
    vector<string> temp;
    void backtrack(const string &s, int start)
    {
        if (start == s.size())
        {
            ans.push_back(temp);
        }
        for (int j = start; j < s.size(); j++)
        {
            if (f[start][j])
            {
                temp.push_back(s.substr(start, j - start + 1));
                backtrack(s, j + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        f.assign(s.size(), vector<int>(s.size(), true));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }
        backtrack(s, 0);
        return ans;
    }
};
// @lc code=end
