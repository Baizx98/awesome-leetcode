/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
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
    int removeElement(vector<int> &nums, int val)
    {
        int s = 0, f = 0;
        for (; f < nums.size(); f++)
        {
            if (nums[f] != val)
            {
                nums[s] = nums[f];
                s++;
            }
        }
        return s;
    }
};
// @lc code=end
