/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0; // 起点
        int total = 0; // 总油量-总消耗量，当走完一圈时判断总油量和总消耗量大小关系
        int curr = 0;  // 当前剩余油量+当前加油站油量-去下一个加油站消耗的油量
        for (int i = 0; i < gas.size(); i++)
        {
            curr += gas[i] - cost[i]; // 此时curr为到了下一个加油站之后加油之前的剩余油量
            total += gas[i] - cost[i];
            if (curr < 0)
            {
                curr = 0;
                start = i + 1;
            }
        }
        if (total >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};
// @lc code=end
