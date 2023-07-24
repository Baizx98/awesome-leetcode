/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        // long i=1;
        // while(i*i<num)i++;
        // return i*i==num;
        int l=0,r=num;
        while(l<=r){
            int mid=l+(r-l)/2;
            long square=(long)mid*mid;
            if(square<num){
                l=mid+1;
            }else if(square>num){
                r=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

