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
    pair<int, int> down{1, 0};
    pair<int, int> right{0, 1};
    pair<int, int> up{-1, 0};
    pair<int, int> left{0, -1};
};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0, y = 0, state = 0;
        vector<vector<bool>> identity_matrix(matrix.size(), vector<bool>(matrix[0].size()));
        vector<int> result;
        result.push_back(matrix[0][0]);
        identity_matrix[0][0] = true;
        int full_size = matrix.size() * matrix[0].size() - 1;

        while (full_size > 0) {
            pair<int&, int&> location{x, y};
            while(move(matrix, identity_matrix, result, location, state)) {
                full_size--;
            }
        }

        return result;
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
        vector<int>& result,
        pair<int&, int&>& location,
        int& state
        ) {
        direction d;
        int x = location.first, y =location.second;
        if (!identity_matrix[x][y]) result.push_back(matrix[x][y]);
        identity_matrix[x][y] = true;
        switch (state)
        {
        case 0:
            x += d.right.first, y += d.right.second;
            if (x < matrix.size() && y < matrix[0].size() && !identity_matrix[x][y]) {
                // identity_matrix[x][y]  = true;
                // result.push_back(matrix[x][y]);
                location.first += d.right.first, location.second += d.right.second;
            } else {
                state = changestate(state);
                return false;
            }
            break;
        
        case 1:
            x += d.down.first, y += d.down.second;
            if (x < matrix.size() && y < matrix[0].size() && !identity_matrix[x][y]) {
                // identity_matrix[x][y] = true;
                // result.push_back(matrix[x][y]);
                location.first += d.down.first, location.second += d.down.second;
            } else {
                state = changestate(state);
                return false;
            }
            break;

        case 2:
            x += d.left.first, y += d.left.second;
            if (x < matrix.size() && y < matrix[0].size() && !identity_matrix[x][y]) {
                // identity_matrix[x][y] = true;
                // result.push_back(matrix[x][y]);
                location.first += d.left.first, location.second += d.left.second;
            } else {
                state = changestate(state);
                return false;
            }
            break;

        default:
            x += d.up.first, y += d.up.second;
            if (x < matrix.size() && y < matrix[0].size() && !identity_matrix[x][y]) {
                // identity_matrix[x][y] = true;
                // result.push_back(matrix[x][y]);
                location.first += d.up.first, location.second += d.up.second;
            } else {
                state = changestate(state);
                return false;
            }
        }

        return true;
    }

};

// @lc code=end

