/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        height = grid.size(), length = grid[0].size();
        visited = vector<vector<bool>>(height, vector<bool>(length, false));
        int count = 0;
        int i = 0, j = 0;

        while(!out_of_bound(i, j)) {
            dfs(grid, make_pair(i, j), grid[i][j]);

            if (grid[i][j] == '1') {
                count++;
            }

            go_to_next(i, j);
        }

        return count;
    }

    bool out_of_bound(const int i, const int j) {
        return i >= height || j >= length || i < 0 || j < 0;
    }

    void dfs(const vector<vector<char>>& grid, const pair<int, int> position, const char origin) {
        if (out_of_bound(position.first, position.second)) return;

        if (visited[position.first][position.second] || grid[position.first][position.second] != origin) return;
        else visited[position.first][position.second] = true;

        dfs(grid, make_pair(position.first + 1, position.second), origin);
        dfs(grid, make_pair(position.first, position.second + 1), origin);
        dfs(grid, make_pair(position.first, position.second - 1), origin);
        dfs(grid, make_pair(position.first - 1, position.second), origin);
    }

    void go_to_next(int& i, int& j) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < length; x++) {
                if (!visited[y][x]) {
                    i = y;
                    j = x;
                    return;
                }
            }
        }

        i = j = -1;
        return;
    }


private:
    int length, height;
    vector<vector<bool>> visited;
};

// int main() {
//     vector<vector<char>> grid = {
//         {'0', '1', '0'},
//         {'1', '0', '1'},
//         {'0', '1', '0'}
//     };

//     Solution s;
//     cout << s.numIslands(grid) << endl;
//     return 0;
// }
// @lc code=end
