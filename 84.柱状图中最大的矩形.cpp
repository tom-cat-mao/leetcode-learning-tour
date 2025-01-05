/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.emplace(heights.begin(), 0);
        heights.emplace_back(0);
        vector<int> one_way_stack;
        int length = heights.size();
        int ans = 0;

        for (int i = 0; i < length; i++) {
            int h = heights.at(i);
            while (!one_way_stack.empty() && h < heights.at(one_way_stack.back())) {
                int dh = heights.at(one_way_stack.back());
                one_way_stack.pop_back();
                int dw = i - one_way_stack.back() - 1;
                ans = max(ans, dh * dw);
            }

            one_way_stack.emplace_back(i);
        }

        return ans;
    }
};
// @lc code=end
