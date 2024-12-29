/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        find_next(vector<int>(), candidates, target);
        return result;
    }

    void find_next(const vector<int>& current_list, const vector<int>& candidates, int sum) {
        if (sum == 0) {
            vector<int> temp(current_list);
            sort(temp.begin(), temp.end());
            if (judgset.find(temp) != judgset.end()) {
                return;
            }

            result.push_back(current_list);
            judgset.insert(temp);
            return;
        }

        for (const int num: candidates) {
            if (num > sum) break;
            vector<int> next(current_list);
            next.push_back(num);
            find_next(next, candidates, sum - num);
        }
    }

private:
    vector<vector<int>> result;
    set<vector<int>> judgset;
};
// @lc code=end

