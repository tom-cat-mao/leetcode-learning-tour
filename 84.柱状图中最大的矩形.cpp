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
        heights.emplace(heights.begin(), 0); // 预处理， 确保在计算过程中，所有柱子都能被处理，不会因为边界条件而遗漏
        heights.emplace_back(0);
        vector<int> one_way_stack; // 单调递增栈
        int length = heights.size();
        int ans = 0;

        for (int i = 0; i < length; i++) {
            int h = heights.at(i);
            while (!one_way_stack.empty() && h < heights.at(one_way_stack.back())) {
                int dh = heights.at(one_way_stack.back()); // 栈顶元素的高度
                one_way_stack.pop_back(); // 弹出栈顶元素
                int dw = i - one_way_stack.back() - 1; // 宽度为当前元素索减去当前栈顶元素的索引再减一
                ans = max(ans, dh * dw);
            }

            one_way_stack.emplace_back(i);
        }

        return ans;
    }
};
// @lc code=end
