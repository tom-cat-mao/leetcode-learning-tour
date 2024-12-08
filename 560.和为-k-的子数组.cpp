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
        int count = 0;
        map<int, int> countTo;
        countTo.insert(make_pair(0, 1));
        int pre = 0;

        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];

            if (countTo.find(pre - k) != countTo.end()) {
                count += countTo[pre - k];
            }

            countTo[pre]++;
        }

        return count;
    }
            
};
// @lc code=end

