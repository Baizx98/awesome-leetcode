/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},

        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    vector<string> ans;
    string temp;
    void backtrack(const string &digits, int index)
    {
        // index用来遍历数字,遍历完所有的字母后结束递归
        if (index == digits.size())
        {
            ans.push_back(temp);
            return;
        }

        string letters = phoneMap[digits[index]];
        // 处理数字对应的每个字符，没处理完一个字符，在循环中递归处理下一个数字
        for (int i = 0; i < letters.size(); i++)
        {
            temp.push_back(letters[i]);
            backtrack(digits, index + 1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return {};
        backtrack(digits, 0);
        return ans;
    }
};
// @lc code=end
