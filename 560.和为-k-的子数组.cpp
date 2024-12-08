/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
                if (sum == k) {
                    result++;
                } else if (sum > k) {
                    break;
                }
            }
        }

        return result;
    }
            
};
// @lc code=end

