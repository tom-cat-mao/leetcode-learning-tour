/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

/* 单调队列方法 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_vec;
        deque<int> doubleq;

        for (int i = 0; i < nums.size(); i++) {
            /** if the front element has pass the k length 
             * just pop it
             */
            while(!doubleq.empty() && i - doubleq.front() >= k) {
                doubleq.pop_front();
            }

            /** if the last element is smaller than current 
             * just pop the last one
             */
            while(!doubleq.empty() && nums[i] > nums[doubleq.back()]) {
                doubleq.pop_back();
            }

            doubleq.push_back(i);

            if (i >= k - 1) {
                max_vec.push_back(nums[doubleq.front()]); // push to the answer
            }
        }


        return max_vec;
    }
};
// @lc code=end

