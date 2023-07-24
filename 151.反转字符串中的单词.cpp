/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> tokens;
        int l = 0, r = 0;
        while (l < s.length())
        {
            while (s[l] == ' ')
            {
                l++;
            }
            r = l + 1;
            while (r < s.length() && s[r] != ' ')
            {
                r++;
            }
            tokens.push_back(s.substr(l, r - l));
            l = r;
        }
        reverse(tokens.begin(), tokens.end());
        string ans;
        for (auto word : tokens)
        {
            ans += " " + word;
        }
        int first = ans.find_first_not_of(" ");
        int last = ans.find_last_not_of(" ");
        return ans.substr(first, last - first + 1);
    }
};
// @lc code=end
