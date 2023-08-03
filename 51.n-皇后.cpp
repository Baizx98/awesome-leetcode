/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
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
    vector<vector<string>> ans;
    bool isValid(int row, int col, vector<string> chessboard, int n)
    {
        // 检查列
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][col] == 'Q')
            {
                return false;
            }
        }

        // 检查45° 只需要向上检查，不需要向下检查，因为下面的还没填充好呢
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        // 检查135°
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void backtrack(int n, int row, vector<string> &chessboard)
    {
        if (row == n)
        {
            // row初始等于0
            ans.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, chessboard, n))
            {
                chessboard[row][col] = 'Q';
                backtrack(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> chessboard(n, string(n, '.'));
        backtrack(n, 0, chessboard);
        return ans;
    }
};
// @lc code=end
