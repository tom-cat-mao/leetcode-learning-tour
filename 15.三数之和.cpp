/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        int i = 0, j = length - 1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (
            ; 
            i < length - 2; 
            i = find_next(nums, i, length - 2, true)
        ) {
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if (nums[i] + nums[length - 1] + nums[length - 2] < 0) continue;
            for (
                j = i + 1;
                j < length - 1; 
                j = find_next(nums, j, nums.size() - 1, true)
                ) {
                for (
                    int k = nums.size() - 1;
                    k > j; 
                    k = find_next(nums, k, j, false)
                    ) {
                        int s = nums[i] + nums[j] + nums[k];
                    if (
                        (s == 0)
                    ) {
                        result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    } else if (s < 0) {
                        break;
                    }
                }
            }
        }

        return result;
    }

    // int between_i_j(vector<int>& nums, int i, int j) {
    //     int k = i + 1;

    //     for (; k < j; k++) {
    //         if (
    //             (nums[i] + nums[k] + nums[j] == 0) && 
    //             different(vector<int>{i, k ,j})
    //             ) {
    //                 return k;
    //         }
    //     }

    //     return -1;
    // }

  
    // bool result_equal(const vector<vector<int>>& nums, const vector<int>& num)  {
    //     for (const vector<int>& instance: nums) {
    //         if (vector_equal(instance, num)) {
    //             return true;
    //         }
    //     }

    //     return false;
    // }

    // bool vector_equal(const vector<int>& nums1, const vector<int>& nums2) {
        // set<int> n1(nums1.begin(), nums1.end());
        // set<int> n2(nums2.begin(), nums2.end());

        // return n1 == n2;
    // }

    inline int find_next(vector<int>& ordered_num, int i, int border, bool larger) {
        if (larger) {
            do {
                i++;
                if (ordered_num[i] != ordered_num[i - 1]) {
                    return i;
                }
            } while(i < border);
        } else {
            do {
                i--;
                if (ordered_num[i] != ordered_num[i + 1]) {
                    return i;
                }
            } while(i > border);
        }

        return -1;
    }
};
// @lc code=end

