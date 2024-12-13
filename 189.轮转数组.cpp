/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int interval = nums.size() - k;

        for (int i = nums.size() - 1; i > interval - 1; i--) {
            int temp = nums[i];
            nums[i] = nums[i - k];
            nums[i - k] = temp;
        }
    }
};
// @lc code=end

