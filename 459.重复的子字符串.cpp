/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
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
    bool repeatedSubstringPattern(string s)
    {
        bool flag = false;
        if (s.length() == 1)
        {
            return false;
        }

        for (int step = 1; step <= s.length() / 2; step++)
        {
            flag = true;
            if (s.length() % step != 0)
                continue;

            for (int i = 0; i < step; i++)
            {
                for (int j = i; j < s.length(); j += step)
                {
                    if (s[i] != s[j])
                        flag = false & flag;
                }
            }
            if (flag)
                return flag;
        }
        return false;
    }
};
// @lc code=end
