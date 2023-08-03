/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include <vector>
#include <string>
#include <algorithm>
#include <map>
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
    unordered_map<string, map<string, int>> targets;
    bool backtrack(int ticketNum, vector<string> &ans)
    {
        if (ans.size() == ticketNum + 1)
        {
            return true;
        }
        // ans中的最后一个字符串代表了上一程的目的地，也就是下一程的出发地,取到的target就是下一程的目的地，
        for (pair<const string, int> &target : targets[ans[ans.size() - 1]])
        {
            if (target.second > 0) // 目的地还有票可去
            {
                ans.push_back(target.first);
                target.second--;
                if (backtrack(ticketNum, ans))
                    return true;
                ans.pop_back();
                target.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        vector<string> ans;
        for (const vector<string> &ticket : tickets)
        {
            targets[ticket[0]][ticket[1]]++; // unordered_map(from,map(to,nums))
        }
        ans.push_back("JFK");
        backtrack(tickets.size(), ans);
        return ans;
    }
};
// @lc code=end
