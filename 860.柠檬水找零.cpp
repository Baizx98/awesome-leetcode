/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
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
    bool lemonadeChange(vector<int> &bills)
    {
        int money[3] = {0, 0, 0}; // 0代表5元，1代表10元，2代表20元
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                money[0]++;
            }
            if (bills[i] == 10)
            {
                money[1]++;
                if (money[0] > 0)
                    money[0]--;
                else
                    return false;
            }
            if (bills[i] == 20)
            {
                money[2]++;
                if (money[1] >= 1 && money[0] >= 1)
                {
                    money[1]--;
                    money[0]--;
                }
                else if (money[1] < 1 && money[0] >= 3)
                {
                    money[0] -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
