/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=0,f=0;
        for(;f<nums.size();f++){
            if(nums[f]!=0){
                nums[s++]=nums[f];
            }
        }
        for(;s<nums.size();s++)
            nums[s]=0;
    }
};
// @lc code=end

