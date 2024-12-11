/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
struct direction {
    pair<int, int> right{1, 0};
    pair<int, int> down{0, 1};
    pair<int, int> left{-1, 0};
    pair<int, int> up{0, -1};
};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0, y = 0, state = 0;
        vector<vector<bool>> identity_matrix(matrix.size(), vector<bool>(matrix[0].size()));
        int full_size = matrix.size() * matrix[0].size();

        while (full_size >= 0) {
            pair<int&, int&> location{x, y};
            while(move(matrix, identity_matrix, location, state)) {
                full_size--;
            }
        }

        return vector<int>();
    }

    int changestate (int state) {
        int s = state + 1;

        if (s > 3) {
            return 0;
        }

        return s;
    }

    bool move(
        const vector<vector<int>>& matrix, 
        vector<vector<bool>>& identity_matrix,
        pair<int&, int&> location,
        int state
        ) {
        direction d;
        switch (state)
        {
        case 0:
            if (!identity_matrix[location.first + d.right.first][location.second + d.right.second]) {
                identity_matrix[location.first + d.right.first][location.second + d.right.second]  = true;
                location.first += d.right.first, location.second += d.right.second;
            } else return false;
            break;
        
        case 1:
            if (!identity_matrix[location.first + d.down.first][location.second + d.down.second]) {
                identity_matrix[location.first + d.down.first][location.second + d.down.second] = true;
                location.first += d.down.first, location.second += d.down.second;
            } else return false;
            break;

        case 2:
            if (!identity_matrix[location.first + d.left.first][location.second + d.left.second]) {
                identity_matrix[location.first + d.left.first][location.second + d.left.second] = true;
                location.first += d.left.first, location.second += d.left.second;
            } else return false;
            break;

        default:
            if (!identity_matrix[location.first + d.up.first][location.second + d.up.second]) {
                identity_matrix[location.first + d.up.first][location.second + d.up.second] = true;
                location.first += d.up.first, location.second += d.left.second;
            } else return false;
        }

        return true;
    }

};
// @lc code=end

