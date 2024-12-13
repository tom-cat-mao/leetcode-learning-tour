/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftside(nums.size());
        vector<int> rightside(nums.size());

        leftside[0] = 1;
        rightside[nums.size() - 1] = 1;

        for (int i = 1; i < nums.size(); i++) leftside[i] = leftside[i - 1] * nums[i - 1];

        for (int i = nums.size() - 2; i > -1; i--) rightside[i] = rightside[i + 1] * nums[i + 1];

        vector<int> result;

        for (int i = 0; i < nums.size(); i++) result.push_back(leftside[i] * rightside[i]);

        return result;
    }
};
// @lc code=end

