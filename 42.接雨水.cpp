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
        stack<int> mystack;

        mystack.push(0);

        for (int i = 1; i < height.size(); i++) {
            while(!mystack.empty() && height[i] > height[mystack.top()]) {
                int n1 = mystack.top();
                mystack.pop();
                
                if (!mystack.empty()) {
                    int n2 = mystack.top();
                    int h = min(height[n2], height[i]) - height[n1]; 
                    int w = i - n2 - 1;
                    volume += h * w;
                }
            }

            mystack.push(i);
        }

        return volume;
    }

};
// @lc code=end

