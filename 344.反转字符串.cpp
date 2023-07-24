/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
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
    void reverseString(vector<char> &s)
    {
        // 非空判断 一个判断
        if (s.size() <= 1)
        {
            return;
        }
        // 左右指针
        int l = 0,
            r = s.size() - 1;
        while (l < r)
        {
            char temp = s[r];
            s[r] = s[l];
            s[l] = temp;
            l++;
            r--;
        }
    }
};
// @lc code=end
