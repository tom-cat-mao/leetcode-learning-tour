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
        int clength = nums.size() - k % nums.size();
        vector<int> temp;
        for (int i = clength; i < nums.size(); i++) {
            temp.push_back(nums[i]);
        }

        for (int i = 0; i < clength; i++) {
            temp.push_back(nums[i]);
        }

        nums = temp;
    }
};
// @lc code=end

