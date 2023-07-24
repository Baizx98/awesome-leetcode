/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
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
    bool isHappy(int n)
    {
        unordered_set<int> record;
        int count = 0;
        int temp = n;
        while (true)
        {
            while (temp > 0)
            {
                count += pow((temp % 10), 2);
                temp /= 10;
            }
            if (count == 1)
                return true;
            if (record.find(count) != record.end()) // cycle！！
                return false;
            else
                record.insert(count);
            temp = count;
            count = 0;
        }
    }
};
// @lc code=end
