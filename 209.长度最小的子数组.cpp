/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0;
        int ans=0;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            r++;
            while(sum>=target){
                ans=ans==0 ? r:min(ans,r-l);
                sum-=nums[l];
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end

