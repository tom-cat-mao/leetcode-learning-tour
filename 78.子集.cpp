/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) return vector<vector<int>>();
        int totalSubsets = 1 << length;
        vector<vector<int>> result;

        for (int i = 0; i < totalSubsets; i++) {
            vector<int> currentSubset;

            for (int j = 0; j < length; j++) {
                if ((i & (1 << j)) != 0) currentSubset.push_back(nums.at(j));
            }

            result.push_back(currentSubset);
        }
        return result;
    }

private:
};
// @lc code=end
