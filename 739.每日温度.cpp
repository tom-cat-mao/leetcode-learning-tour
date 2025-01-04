/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int length = temperatures.size();
        vector<int> ans(length, 0);
        stack<int> one_way_stack;

        for (int i = length - 1; i >= 0; i--) {
            while (
                !one_way_stack.empty() && 
                temperatures[one_way_stack.top()] <= temperatures[i]
                ) {
                one_way_stack.pop();
            }

            if (!one_way_stack.empty()) {
                ans[i] = one_way_stack.top() - i;
            }

            one_way_stack.push(i);
        }

        return ans;
    }
};
// @lc code=end

