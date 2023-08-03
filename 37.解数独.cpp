/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
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
    bool isValid(int row, int col, int val, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        { // 判断行里是否重复
            if (board[row][i] == val)
            {
                return false;
            }
        }
        for (int j = 0; j < 9; j++)
        { // 判断列里是否重复
            if (board[j][col] == val)
            {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
        { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (board[i][j] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool backtrack(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    continue;
                }
                for (char k = '1'; k <= '9'; k++)
                {
                    if (isValid(i, j, k, board))
                    {
                        board[i][j] = k;
                        if (backtrack(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false; // 遍历完所有的1-9还是不合法，返回false
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        backtrack(board);
    }
};
// @lc code=end
