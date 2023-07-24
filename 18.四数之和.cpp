/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int size = nums.size();
        if (size < 4)
        {
            return {};
        }

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 剪枝
            // if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            //     break;
            // if ((long)nums[i] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target)
            //     break;
            for (int j = i + 1; j < size - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                // if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                //     break;
                // if (nums[i] + nums[j] + nums[size - 1] + nums[size - 2] > target)
                //     break;
                int left = j + 1, right = size - 1;
                while (left < right)
                {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++, right--;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                        // while (left < right && nums[left] == nums[left - 1])
                        //     left++;
                    }
                    else
                    {
                        right--;
                        // while (left < right && nums[right] == nums[right + 1])
                        //     right--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
