/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        getPermutations(nums, 0, result);

        return result;
    }

    void getPermutations(vector<int>& array, int start, vector<vector<int>>& result) {
        if (start == array.size() - 1) {
            result.push_back(array);
            return;
        }

        for (int i = start; i < array.size(); i++) {
            swap(array.at(start), array.at(i));
            getPermutations(array, start + 1, result);
            swap(array.at(start), array.at(i));
        }
    }

};
// @lc code=end
