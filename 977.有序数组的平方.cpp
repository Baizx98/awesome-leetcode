/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
          int l=0,r=nums.size()-1,pos=nums.size()-1;
          vector<int> ans(nums.size());
          while(l<=r){
            if(nums[l]*nums[l]>nums[r]*nums[r]){
                ans[pos]=nums[l]*nums[l];
                pos--;
                l++;
            }else{
                ans[pos]=nums[r]*nums[r];
                pos--;
                r--;
            }
          }
          return ans;
    }
};
// @lc code=end

