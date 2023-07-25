/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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
    bool isValid(string s)
    {
        stack<char> ss;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            cout << 1 << " ";
            if (*it == '[' || *it == '(' || *it == '{')
            {
                ss.push(*it);
            }
            if (ss.empty())
                return false;
            if (*it == ']' && ss.top() == '[')
            {
                ss.pop();
            }
            else if (*it == ']' && ss.top() != '[')
                return false;
            if (*it == '}' && ss.top() == '{')
            {
                ss.pop();
            }
            else if (*it == '}' && ss.top() != '{')
                return false;
            if (*it == ')' && ss.top() == '(')
            {
                ss.pop();
            }
            else if (*it == ')' && ss.top() != '(')
                return false;
        }
        return ss.empty();
    }
};
// @lc code=end
