/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> queens(n);
        vector<int> col(n), diag1(n * 2 - 1), diag2(n * 2 - 1), on_path(n);
        function<void(int)> dfs = [&](int r) {
            if (r == n) {
                vector<string> path(n);
                for (int i = 0; i < n; i++) {
                    path.at(i) = string(col.at(i), '.') + 'Q' + string(n - 1 - col.at(i), '.');
                }

                ans.push_back(path);
            }

            for (int c = 0; c < n; c++) {
                int d1 = r + c;
                int d2 = c - r + n - 1;
                if (!on_path.at(c) && !diag1.at(d1) && !diag2.at(d2)) {
                    col.at(r) = c;
                    on_path.at(c) = diag1.at(d1) = diag2.at(d2) = true;
                    dfs(r + 1);
                    on_path.at(c) = diag1.at(d1) = diag2.at(d2) = false;
                }
            }
        };

        dfs(0);
        return ans;
    }

private:
};
// @lc code=end
