/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> LeftMax(height.size());
        vector<int> RightMax(height.size());
        int left, right, volume;
        left = right = volume = 0;

        for (int i = 0; i < height.size(); i++) {
            left = height[i] > left ? height[i] : left;

            LeftMax[i] = left;
        }

        for (int i = height.size() - 1; i > -1; i--) {
            right = height[i] > right ? height[i] : right;

            RightMax[i] = right;
        }

        for (int i = 0; i < height.size(); i++)
            volume += min(LeftMax[i], RightMax[i]) - height[i];

        return volume;
    }

};
// @lc code=end

