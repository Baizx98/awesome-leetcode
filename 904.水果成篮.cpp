/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0;
        unordered_map<int,int> cnt;
        int ans=0;
        while(r<fruits.size()){
            ++cnt[fruits[r]]; //hash 键对应的值++
            while(cnt.size()>2){
                auto it=cnt.find(fruits[l]);
                --it->second;//value
                if(it->second==0){
                    cnt.erase(it);
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
// @lc code=end

