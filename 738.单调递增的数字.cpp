/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
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
    int monotoneIncreasingDigits(int n)
    {
        string s = to_string(n);
        int flag = s.length();
        for (int i = s.length() - 1; i > 0; i--)
        {
            if (s[i] < s[i - 1])
            {
                flag = i;
                s[i - 1]--;
            }
        }
        for (int i = flag; i < s.length(); i++)
        {
            s[i] = '9';
        }
        return stoi(s);
    }
};
// @lc code=end
