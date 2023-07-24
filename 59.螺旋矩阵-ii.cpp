/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // int sx=0,sy=0;
        // int i=0,j=0;
        // int loop=n/2;
        // int offset=1;
        // int count=1;
        // int mid=n/2;
        // vector<vector<int>> res(n,vector<int>(n,0));

        // while(loop--){
        //     i=sx;
        //     j=sy;
        //     for(j=sy;j<=n-offset;j++){
        //         res[i][j]=count++;
        //     }
        //     for(i=sx;i<n-offset;i++){
        //         res[i][j]=count++;
        //     }
        //     for(;j>sy;j--){
        //         res[i][j]=count++;
        //     }
        //     for(;i>sx;i--){
        //         res[i][j]=count++;
        //     }
        //     sx++,sy++;
        //     offset++;
        // }
        // if(n%2==1){
        //     res[mid][mid]=count;
        // }
        // return res;
        int t = 0;      // top
        int b = n-1;    // bottom
        int l = 0;      // left
        int r = n-1;    // right
        vector<vector<int>> ans(n,vector<int>(n));
        int k=1;
        while(k<=n*n){
            for(int i=l;i<=r;++i,++k) ans[t][i] = k;
            ++t;
            for(int i=t;i<=b;++i,++k) ans[i][r] = k;
            --r;
            for(int i=r;i>=l;--i,++k) ans[b][i] = k;
            --b;
            for(int i=b;i>=t;--i,++k) ans[i][l] = k;
            ++l;
        }
        return ans;
    }
};
// @lc code=end

