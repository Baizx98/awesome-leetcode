/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
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
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mag;
        for (char s : magazine)
        {
            mag[s]++;
        }
        for (char s : ransomNote)
        {
            if (mag[s] > 0)
                mag[s]--;
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
