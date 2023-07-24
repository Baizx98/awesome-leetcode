/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() == 0 || nums2.size() == 0)
        {
            return vector<int>();
        }

        unordered_set<int> cross;
        unordered_set<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            cross.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (cross.find(nums2[i]) != cross.end())
                ans.insert(nums2[i]);
        }
        vector<int> ansV;
        for (auto iter = ans.begin(); iter != ans.end(); iter++)
        {
            ansV.push_back(*iter);
        }
        return ansV;
    }
};
// @lc code=end
