/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> q;
        for (string s : tokens)
        {
            if (s != "+" && s != "-" && s != "*" && s != "/")
            {
                q.push(stoi(s));
            }
            if (s == "+")
            {
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                q.push(b + a);
            }
            if (s == "-")
            {
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                q.push(b - a);
            }
            if (s == "*")
            {
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                q.push(b * a);
            }
            if (s == "/")
            {
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                q.push(b / a);
            }
        }
        return q.top();
    }
};
// @lc code=end
