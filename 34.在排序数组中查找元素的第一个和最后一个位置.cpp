/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start = 0, end = nums.size() - 1, getone = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums.at(mid) == target) {
                getone = mid;
                break;
            } else if (nums.at(mid) > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        if (getone == -1) return vector<int>{-1, -1};

        int left = getone - 1, right = getone + 1;

        while (left >= 0) {
            if (nums.at(left) != target) break;
            left--;
        }

        while (right < nums.size()) {
            if (nums.at(right) != target) break;
            right++;
        }

        return vector<int>{left + 1, right - 1};
    }
};
// @lc code=end

