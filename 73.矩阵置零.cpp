/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        multimap<int, int> ZeroMap;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) ZeroMap.insert(make_pair(i, j));
            }
        }

        for (const pair<int, int>& p : ZeroMap) {
            convert(matrix, p);
        }
    }

    void convert(vector<vector<int>>& matrix, const pair<int, int>& point) {
        for (int x = 0; x < matrix[0].size(); x++) matrix[point.first][x] = 0;

        for (int y = 0; y < matrix.size(); y++) matrix[y][point.second] = 0;
    }
};
// @lc code=end

