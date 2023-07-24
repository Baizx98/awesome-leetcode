/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
 #include<vector>

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // unordered_map<char,int> need;
        // for(char c:t){
        //     need[c]++;
        // }
        // int cnt=t.length(); //需要元素，也就是t中包含的元素的数量，其他元素的数量不计入改变量
        // int l=0,r=0;
        // int res_l=0,res_r=INT_MAX;

        // while(r<s.length()){
        //     if(need.count(s[r])){
        //         need[s[r]]--;

        //     }

        //     if(need[s[r]]>0){
        //         cnt--;
        //     }
        //     while(cnt==0){
        //         if(r-l<res_r-res_l){
        //             res_l=l;
        //             res_r=r;
        //         }
        //         if(need[s[l]]>0){
        //             need[s[l]]++;
        //             l++;
        //         }
        //     }                
        //     r++;
        // }
        // return (res_r==INT_MAX) ?"" : s.substr(res_l,res_r-res_l+1);
        unordered_map<char,int>ht,hs;
        for(char c:t) ht[c]++;
        string res;
        int cnt=0;
        for(int i=0,j=0;i<s.size();i++)
        {
            hs[s[i]]++;
            if(hs[s[i]]<=ht[s[i]]) ++cnt;
            while(j<i&&hs[s[j]]>ht[s[j]]) hs[s[j++]]--;
            if(cnt==t.size())
            {
                if(res.empty()||res.size()>i-j+1) res=s.substr(j,i-j+1);
            }
        }
        return res;
    }
};
// @lc code=end

