/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        // if(x==0)
        //     return 0;
        // double C=x,xi=x;
        // while(1)
        // {
        //     double x_next=(xi+C/xi)/2;
        //     if(fabs(x_next-xi)<1e-7){
        //         break;
        //     }
        //     xi=x_next;
        // }
        // return int(xi);
        //二分法
        int l=0,r=x,ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if((long long)mid*mid<=x){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};
// @lc code=end

