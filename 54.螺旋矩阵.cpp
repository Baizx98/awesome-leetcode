/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int t=0,b=m-1,l=0,r=n-1;
        vector<int> res(m*n,0);
        int mn=m*n;
        int k=0;
        while(k<mn){
            for(int i=t,j=l;j<=r && k<mn;j++){
                res[k++]=matrix[i][j];
            }
            t++;
            for(int i=t,j=r;i<=b && k<mn;i++){
                res[k++]=matrix[i][j];
            }
            r--;
            for(int i=b,j=r;j>=l && k<mn;j--){
                res[k++]=matrix[i][j];
            }
            b--;
            for(int i=b,j=l;i>=t && k<mn;i--){
                res[k++]=matrix[i][j];
            }
            l++;
        }
        return res;
    }
};
// @lc code=end

