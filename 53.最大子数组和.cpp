/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = INT16_MIN;
        for (const auto& x : nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }

        return maxAns;
    }
};
// @lc code=end

