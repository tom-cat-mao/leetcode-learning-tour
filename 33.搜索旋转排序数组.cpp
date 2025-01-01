/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return mergefind(nums, 0, nums.size() - 1, target);
    }

private:
    int mergefind(const vector<int>& nums, int start, int end, int target) {
        int length = end - start + 1;
        if (length == 1) {
            if (nums.at(start) == target) {
                return start;
            } else {
                return -1;
            }
        }

        int mid = (start + end) >> 1;
        if (nums.at(mid) == target) return mid;

        int left = mergefind(nums, start, mid, target);
        int right = mergefind(nums, mid + 1, end, target);

        return max(left, right);
    }
};
// @lc code=end

