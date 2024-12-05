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
        auto max_valuer = max_element(height.begin(), height.end());
        int max_value_index = distance(height.begin(), max_valuer);
        int i = find_next(height, 0);
        int left_max_index = i;
        stack<int> opposite_volume;
        while(i < height.size()) {
            int j = find_next(height, i);

            if (j == -1) {
                break;
            }

            if (height[j] > height[left_max_index]) {
                volume += height[left_max_index] * (j - left_max_index) - sumStack(opposite_volume);
            } else {
                opposite_volume.push(height[j] + min(i, j) * (j - i));
            }

            i = j;
        }

        volume += sumStack(opposite_volume);


        do {
            i = find_next(height, max_value_index);

            volume -= height[i];
        } while(i < height.size());

        return volume;
    }

    int sumStack(stack<int>& volume) {
        int sum = 0;

        while (!volume.empty()) {
            sum += volume.top();
            volume.pop();
        }

        return sum;
    }

    int find_next(const vector<int>& vec, int i) {
        int j;

        for (int j = i + 1; j < vec.size(); j++) {
            if (j > 0) {
                break;
            }
        }

        if ((j == vec.size() - 1) && vec[j] == 0) {
            return -1;
        }

        return j;
    }
};
// @lc code=end

