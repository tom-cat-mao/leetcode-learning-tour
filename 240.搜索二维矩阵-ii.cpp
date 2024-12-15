/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // struct Position {
    //     int i, j;

    //     bool operator==(const Position& p) const {
    //         return i == p.i && j == p.j;
    //     }
    // };
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h_length = matrix.size(), v_length = matrix[0].size();
    //     multimap<int, Position> max_value;

    //     for (int i = 0; i < h_length; i++) max_value.insert(make_pair(matrix[i][0], Position{i, 0}));

    //     int i = 0, j = 0, value = 0;

    //     while(!max_value.empty()) {
    //         auto p = max_value.begin();
    //         value = (*p).first, i = (*p).second.i, j = (*p).second.j;
    //         auto range = max_value.equal_range(value);
    //         for (auto it = range.first; it != range.second; it++) {
    //             if (it -> second == (*p).second) {
    //                 if (distance(range.first, range.second) == 1) max_value.erase(value);
    //                 else max_value.erase(it);

    //                 break;
    //             }
    //         }

    //         if (value == target) return true;

    //         if (value > target) break;

    //         if (value < target && j + 1 < v_length) {
    //             max_value.insert(make_pair(matrix[i][j + 1], Position{i, j + 1}));
    //             continue;
    //         }
    //     }

    //     return false;
        for (int i = 0; i < h_length; i++)
            for (int j = 0; j < v_length; j++)
                if (matrix[i][j] == target) return true;

        return false;
    }
};

// @lc code=end
