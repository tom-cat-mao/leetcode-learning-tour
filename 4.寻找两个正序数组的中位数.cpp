/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto first = nums1.begin(), second = nums2.begin();
        int length = nums1.size() + nums2.size(), count = 0;
        if (!(length & 1)) {
            length = length >> 1;
            while (first != nums1.end() && second != nums2.end() && count < length - 1) {
                if (*first < *second) count++, first++;
                else count++, second++;
            }

            if (count == length - 1) {
                int temp;
                if (first == nums1.end()) {
                    temp = *second;
                    second++;
                    return (temp + *second) / 2.0;
                } else if (second == nums2.end()){
                    temp = *first;
                    first++;
                    return (temp + *first) / 2.0;
                }
                
                if (*first < *second) {
                    temp = *first;
                    first++;
                    if (first != nums1.end()) return (temp + min(*first, *second)) / 2.0;
                    return (temp + *second) / 2.0;
                } else {
                    temp = *second;
                    second++;
                    if (second != nums2.end()) return (temp + min(*first, *second)) / 2.0;
                    return (temp + *first) / 2.0;
                }
            }

            while (first != nums1.end() && count < length - 1) count++, first++;
            while (second != nums2.end() && count < length - 1) count++, second++;

            if (first == nums1.end()) {
                int temp = *second;
                second++;
                return (*second + temp) / 2.0;
            } else {
                int temp = *first;
                first++;
                return (*first + temp) / 2.0;
            }
        } else {
            length = length >> 1;
            while (first != nums1.end() && second != nums2.end() && count < length) {
                if (*first < *second) count++, first++;
                else count++, second++;
            }

            if (count == length) {
                if (first == nums1.end()) return *second;
                else if (second == nums2.end()) return *first;
                else  return min(*first, *second);
            }

            while (first != nums1.end() && count < length) count++, first++;
            while (second != nums2.end() && count < length) count++, second++;

            if (first == nums1.end()) return *second;
            if (second == nums2.end()) return *first;

            return min(*first, *second);
        }

        return 0.0;
    }
};
// @lc code=end

