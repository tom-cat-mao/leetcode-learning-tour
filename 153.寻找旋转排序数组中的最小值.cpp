/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, min = INT16_MAX;

        while (start <= end) {
            int mid = (start + end) >> 1;
            min = std::min(min, nums.at(mid));

            if (nums.at(start) <= nums.at(mid)) {
                min = std::min(min, nums.at(start));
                start = mid + 1;
            } else {
                min = std::min(min, nums.at(mid));
                end = mid - 1;
            }
        }

        return min;
    }
};
// @lc code=end

