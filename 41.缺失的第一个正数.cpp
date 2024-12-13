/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 1) {
            if (nums[0] == 1) return 2;

            return 1;
        }

        set<int> ordered_vec(nums.begin(), nums.end());

        auto it = ordered_vec.begin();

        while (it != ordered_vec.end()) {
            if (*it > 0) break;

            it++;
        }

        if (*it != 1) return 1;

        int interval = 1;
        int temp;
        while (it != ordered_vec.end()) {
            temp = *it;
            it++;
            if (interval != *it - temp)  {
                return temp + 1;
            }
        }

        return temp + 1;
    }
};
// @lc code=end

