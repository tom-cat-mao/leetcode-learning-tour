/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);

        for (const auto& info: prerequisites)
            edges.at(info.at(1)).push_back(info.at(0));

            for (int i = 0; i < numCourses && valid; i++)
                if (!visited.at(i)) dfs(i);

        return valid;
    }

private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

    void dfs(int u) {
        visited.at(u) = 1;
        for (int v: edges.at(u)) {
            if (visited.at(v) == 0) {
                dfs(v);
                if (!valid) return;
            } else if (visited.at(v) == 1) {
                valid = false;
                return;
            }
        }

        visited.at(u) = 2;
    }
};
// @lc code=end
