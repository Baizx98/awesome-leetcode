/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int hashS[26] = {0}, hashP[26] = {0};

        if (s.length() < p.length())
        {
            return vector<int>();
        }

        vector<int> ans;
        for (int i = 0; i < p.length(); i++)
        {
            hashS[s[i] - 'a']++;
            hashP[p[i] - 'a']++;
        }
        if (equal(begin(hashS), end(hashS), begin(hashP)))
            ans.emplace_back(0);
        for (int i = 0; i < s.length() - p.length(); i++)
        {
            hashS[s[i] - 'a']--;
            hashS[s[i + p.length()] - 'a']++;
            if (equal(begin(hashS), end(hashS), begin(hashP)))
                ans.emplace_back(i + 1);
        }
        return ans;
    }
};
// @lc code=end
