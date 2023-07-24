/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <iostream>
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
    string reverseStr(string s, int k)
    {
        int size = s.size();
        int count = size / (2 * k);
        int re = size % (2 * k);
        int co = 0;
        int l, r;
        for (co = 0; co < count; co++)
        {
            /* code */
            l = co * 2 * k;
            r = l + k - 1;
            while (l < r)
            {
                char temp = s[r];
                s[r] = s[l];
                s[l] = temp;
                l++, r--;
            }
        }
        if (re < k && re > 0)
        {
            l = co * 2 * k;
            r = size - 1;
        }
        else if (re >= k && re < 2 * k)
        {
            l = co * 2 * k;
            r = l + k - 1;
        }
        while (l < r)
        {
            char temp = s[r];
            s[r] = s[l];
            s[l] = temp;
            l++, r--;
        }
        return s;
    }
};
// @lc code=end
