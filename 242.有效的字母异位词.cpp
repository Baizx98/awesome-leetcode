/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int ss[26] = {0}, tt[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            ss[index]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            int index = t[i] - 'a';
            tt[index]++;
        }
        for (int i = 0; i < 26; i++)
        {
            cout << ss[i] << tt[i] << endl;
            if (ss[i] != tt[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
