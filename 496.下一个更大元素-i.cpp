/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> h;
        for (int i = 0; i < nums1.size(); i++)
        {
            h[nums1[i]] = i; // 记录元素在nums1中的下标
        }

        stack<int> s;
        s.push(0);
        for (int i = 1; i < nums2.size(); i++)
        {
            if (nums2[i] <= nums2[s.top()])
            {
                s.push(i);
            }
            else
            {
                while (!s.empty() && nums2[i] > nums2[s.top()])
                {
                    if (h.find(nums2[s.top()]) != h.end())
                    {
                        ans[h[nums2[s.top()]]] = nums2[i];
                    }
                    s.pop();
                }
                s.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end
