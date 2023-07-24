/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // key:sorted str ,value:naive str
        unordered_map<string, vector<string>> sta;
        for (string &str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            sta[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = sta.begin(); it != sta.end(); it++)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
// @lc code=end
