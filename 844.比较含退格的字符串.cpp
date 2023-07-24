/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int se=s.length()-1,te=t.length()-1;
        int ss=0,ts=0;
        while(se>=0 || te>=0){
            while(se>=0){
                if(s[se]=='#'){
                    ss++;
                    se--;
                }else if(ss>0){
                    se--;
                    ss--;
                }else{
                    break;
                }
            }

            while(te>=0){
                if(t[te]=='#'){
                    ts++;
                    te--;
                }else if(ts>0){
                    te--;
                    ts--;
                }else{
                    break;
                }
            }
            if(se>=0 && te>=0) {
                if(s[se]!=t[te]){
                    return false;
                }
            }else{
                if(se>=0 || te>=0){
                    return false;
                }
            }
            se--;te--;
        }
        return true;
    }
};
// @lc code=end

