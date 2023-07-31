/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
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
    vector<vector<int>> ans;
    vector<int> temp;
    void helper(int n, int k, int start)
    {
        if (temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            temp.push_back(i);
            helper(n, k, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        helper(n, k, 1);
        return ans;
    }
};
// @lc code=end
