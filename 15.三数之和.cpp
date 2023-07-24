/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int size = nums.size();
        vector<vector<int>> ans;
        if (size < 3)
        {
            return {};
        }
        sort(nums.begin(), nums.end());
        // 每次循环固定一个值，另外两个数使用两端双指针来遍历
        for (int i = 0; i < size - 2; i++)
        {
            if (nums[i] > 0)
                break; // 后面的元素都大于0，就没必要遍历了
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = size - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0)
                {
                    l++;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                }
                else if (sum > 0)
                {
                    r--;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
