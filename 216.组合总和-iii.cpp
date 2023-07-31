/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
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
    int sum = 0;
    vector<vector<int>> ans;
    vector<int> temp;
    void helper(int k, int n, int start)
    {
        // 剪枝
        if (temp.size() > k || sum > n)
            return;
        if (sum == n && temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            sum += i;
            temp.push_back(i);
            helper(k, n, i + 1);
            sum -= i;
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        helper(k, n, 1);
        return ans;
    }
};
// @lc code=end
