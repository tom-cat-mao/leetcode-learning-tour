/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = find(nums, 0, nums.size() - 1, target);
        if (index == -1) return 0;
        if (nums.at(index) < target) return index + 1;
        return index;
    }

    int find(const vector<int>& nums, int start, int end, int target) {
        int length = end - start + 1;
        if (length <= 1) {
            if (nums.at(start) <= target) return start;
            else return -1;
        }  
        int mid = (start + end) / 2;

        int left = find(nums, start, mid, target);
        int right = find(nums, mid + 1, end, target);

        if (right == -1 && left >= 0) {
            return left;
        }

        return right;
    }
};
// @lc code=end

