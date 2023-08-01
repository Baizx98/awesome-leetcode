/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
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
    vector<vector<int>> ans;
    vector<int> path;
    void backtrack(unordered_set<int> &s, vector<int> &nums)
    {
        // v1
        //  if (path.size() == nums.size())
        //  {
        //      ans.push_back(path);
        //      return;
        //  }
        //  for (int i = 0; i < nums.size(); i++)
        //  {
        //      if (i > 0 && nums[i] == nums[i - 1] && s.find(i - 1) == s.end())
        //      {
        //          continue;
        //      }
        //      if (s.find(i) == s.end())
        //      {
        //          s.insert(i);
        //          path.push_back(nums[i]);
        //          backtrack(s, nums);
        //          path.pop_back();
        //          s.erase(i);
        //      }
        //  }
        // v2
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        unordered_set<int> layerSet;
        for (int i = 0; i < nums.size(); i++)
        {
            if (layerSet.find(nums[i]) != layerSet.end())
            {
                continue;
            }

            if (s.find(i) == s.end())
            {
                layerSet.insert(nums[i]);
                s.insert(i);
                path.push_back(nums[i]);
                backtrack(s, nums);
                path.pop_back();
                s.erase(i);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        backtrack(s, nums);
        return ans;
    }
};
// @lc code=end
