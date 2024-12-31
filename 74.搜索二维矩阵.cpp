/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size(), length = matrix.at(0).size(), i = 0, j = length - 1;

        while (i < height && j >= 0) {
            if (matrix.at(i).at(j) == target) return true;

            if (matrix.at(i).at(j) < target) i++;
            else j--;
        }

        return false;
    }
};
// @lc code=end

