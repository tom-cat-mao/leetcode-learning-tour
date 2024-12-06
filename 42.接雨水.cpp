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
        int volume = 0;
        stack<int> index_stack;
        const static int MIN_CAPICITY = 2;

        int i = 0;

        while (i < height.size()) {
            if (index_stack.size() < MIN_CAPICITY) {
                index_stack.push(i);
                i++;
                continue;
            }

            if (height[i] > height[index_stack.top()]) {
                for (
                    int j = index_stack.top(); 
                    !index_stack.empty() && height[i] > height[j]; 
                    j = index_stack.top()
                    ){
                    index_stack.pop();
                    volume += (min(height[i], height[index_stack.top()]) - height[j]) * (i - index_stack.top() - 1);
                }
            }

            index_stack.push(i);

            i++;
        }

        return volume;
    }

};
// @lc code=end

