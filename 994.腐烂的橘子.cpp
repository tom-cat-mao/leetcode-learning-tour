/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        height = grid.size(), length = grid.at(0).size();
        int count = 0;
        fresh = last_fresh = 0;

        for (const auto& row: grid) {
            for (const auto& state: row) {
                if (state == 1) fresh++;
            }
        }

        last_fresh = fresh;

        while (fresh > 0) {
            int i = 0, j = -1;
            pair<int&, int&> position(i, j);
            visited = vector<vector<bool>>(height, vector<bool>(length, false));
            go_to_next(grid, position);
            while (!out_of_bound(position)) {
                checkaround(grid, position);
                go_to_next(grid, position);
            }

            count++;
            if (last_fresh == fresh) return -1;
            last_fresh = fresh;
        }

        return count;
    }

private:
    int length, height, fresh, last_fresh;
    vector<vector<bool>> visited;

    bool out_of_bound(const pair<int, int>& position) {
        return
                0 > position.first ||
                0 > position.second ||
                position.first >= height ||
                position.second >= length;
    }

    void go_to_next(const vector<vector<int>>& grid,pair<int&, int&>& position) {
        for (int j = position.second + 1; j < length; j++) {
            if (!visited.at(position.first).at(j) && grid.at(position.first).at(j) == 2) {
                position.second = j;
                return;
            }
        }

        for (int i = position.first + 1; i < height; i++) {
            for (int j = 0; j < length; j++) {
                if (!visited.at(i).at(j) && grid.at(i).at(j) == 2) {
                    position.first = i, position.second = j;
                    return;
                }
            }
        }

        position.first = -1, position.second = -1;
        return;
    }

    void checkaround(vector<vector<int>>& grid, const pair<int, int>& position) {
        if (out_of_bound(position)) return;
        visited.at(position.first).at(position.second) = true;

        if (!out_of_bound(make_pair(position.first + 1, position.second)) && grid.at(position.first + 1).at(position.second) == 1) {
            grid.at(position.first + 1).at(position.second)++;
            visited.at(position.first + 1).at(position.second) = true;
            fresh--;
        }

        if (!out_of_bound(make_pair(position.first - 1, position.second)) && grid.at(position.first - 1).at(position.second) == 1) {
            grid.at(position.first - 1).at(position.second)++;
            visited.at(position.first - 1).at(position.second) = true;
            fresh--;
        }

        if (!out_of_bound(make_pair(position.first, position.second + 1)) && grid.at(position.first).at(position.second + 1) == 1) {
            grid.at(position.first).at(position.second + 1)++;
            visited.at(position.first).at(position.second + 1) = true;
            fresh--;
        }

        if (!out_of_bound(make_pair(position.first, position.second - 1)) && grid.at(position.first).at(position.second - 1) == 1) {
            grid.at(position.first).at(position.second - 1)++;
            visited.at(position.first).at(position.second - 1) = true;
            fresh--;
        }
    }

    // void dfs(vector<vector<int>>& grid, const pair<int, int>& position, const int origin) {
    //     if (out_of_bound(position)) return;

    //     if (grid[position.first][position.second] == 0 || visited.at(position.first).at(position.second)) return;

    //     if (grid[position.first][position.second] < origin) {
    //         grid.at(position.first).at(position.second)++;
    //         visited.at(position.first).at(position.second) = true;
    //         fresh--;
    //     }

    //     dfs(grid, make_pair(position.first + 1, position.second), origin);
    //     dfs(grid, make_pair(position.first - 1, position.second), origin);
    //     dfs(grid, make_pair(position.first, position.second + 1), origin);
    //     dfs(grid, make_pair(position.first, position.second - 1), origin);
    // }

};

// int main () {
//     Solution s;
//     vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
//     cout << s.orangesRotting(grid) << endl;
//     return 0;
// }

// @lc code=end
