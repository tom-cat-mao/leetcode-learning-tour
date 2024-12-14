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
    struct position {
        int x, y;
    };
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h_length = matrix.size(), v_length = matrix[0].size();
        multimap<int, position> max_value;

        for (int i = 0; i < v_length; i++) max_value.insert(make_pair(matrix[i][0], position{0, i}));

        int i = 0, j = 0, value = 0;

        while(!max_value.empty()) {
            auto p = max_value.begin();
            value = (*p).first, i = (*p).second.y, j = (*p).second.x;
            max_value.erase(value);

            if (value == target) return true;

            if (value > target) break;

            if (value < target && j + 1 < v_length) {
                max_value.insert(make_pair(matrix[i][j + 1], position{j + 1, i}));
                continue;
            }
        }

        return false;
    }
};

int main() {
    Solution so;
    vector<vector<int>> problem{{5, 6, 10, 14}, {6, 10, 13, 18}, {10, 13, 18, 19}};
    if (so.searchMatrix(problem, 14)) cout << "true" << endl;
    else cout << "false" << endl;
}
// @lc code=end
