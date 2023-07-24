#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int mid=0;
        while(l<=r)
        {
            mid=(r+l)/2;
            if(nums[mid]<target)
                l=mid+1;
            if(nums[mid]>target)
                r=mid-1;
            if(nums[mid]==target)
                return mid;
        }
        return -1;
    }
};
// @lc code=end

