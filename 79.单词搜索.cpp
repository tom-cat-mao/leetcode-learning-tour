/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        height = board.size();
        length = board[0].size();
        vector<vector<bool>> visited(height, vector<bool>(length, false));
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < length; ++j) {
                if (goNext(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int height, length;

    bool goNext(const vector<vector<char>>& board, const string& word, vector<vector<bool>>& visited, int x, int y, int index) {
        if (index == word.size()) return true;
        if (x < 0 || x >= height || y < 0 || y >= length || visited[x][y] || board[x][y] != word[index]) {
            return false;
        }

        visited[x][y] = true;
        bool found = goNext(board, word, visited, x + 1, y, index + 1) ||
                     goNext(board, word, visited, x - 1, y, index + 1) ||
                     goNext(board, word, visited, x, y + 1, index + 1) ||
                     goNext(board, word, visited, x, y - 1, index + 1);
        visited[x][y] = false;

        return found;
    }
};
// @lc code=end

