/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
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
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int count = nums.size();
        vector<int> ans(count, -1);
        stack<int> s;
        s.push(0);
        for (int i = 1; i < 2 * nums.size(); i++)
        {
            // if (count == 0)
            // {
            //     break;
            // }

            int j = i % nums.size();
            if (nums[j] <= nums[s.top()])
            {
                s.push(j);
            }
            else
            {
                while (!s.empty() && nums[j] > nums[s.top()])
                {
                    ans[s.top()] = nums[j];
                    // count--;
                    s.pop();
                    cout << 1 << endl;
                }
                s.push(j);
            }
        }
        return ans;
    }
};
// @lc code=end
