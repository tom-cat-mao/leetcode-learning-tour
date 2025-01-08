/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int mv = 0;
        int maxright = 0;
        int count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            maxright = max(maxright, i + nums.at(i));

            if (i == mv) {
                mv = maxright;
                count++;
            }
        }

        return count;
    }
};
// @lc code=end
