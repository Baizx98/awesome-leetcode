/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <vector>
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
    int count = 0;
    string ip;
    vector<string> ans;
    bool isValidIP(string ip)
    {
        if (ip.empty() || ip.size() > 3)
        {
            return false;
        }
        if (ip.size() > 1 && ip[0] == '0')
            return false;
        int num = stoi(ip);
        return num > 255 ? false : true;
    }
    void backtrack(string &s, int start)
    {
        if (count == 4 && ip.size() == s.size() + 3)
        {
            ans.push_back(ip);
            return;
        }
        for (int i = start; i < s.size() && count <= 4; i++)
        {
            string subIP = s.substr(start, i - start + 1);
            if (isValidIP(subIP))
            {
                count++;
                int backLength;
                if (ip == "")
                {
                    ip += subIP;
                    backLength = subIP.size();
                }
                else
                {
                    ip += ".";
                    ip += subIP;
                    backLength = subIP.size() + 1;
                }

                backtrack(s, i + 1);
                ip.resize(ip.size() - backLength);
                count--;
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        backtrack(s, 0);
        return ans;
    }
};
// @lc code=end
