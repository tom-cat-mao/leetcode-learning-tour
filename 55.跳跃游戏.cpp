/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0;

        for (int i = 0; max_index < nums.size() - 1; i++) {
            if (i > max_index) return false;

            max_index = max(max_index, i + nums.at(i));
        }

        return true;

    }
};
// @lc code=end

