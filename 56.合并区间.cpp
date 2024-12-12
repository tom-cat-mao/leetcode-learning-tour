/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> myMap;
       vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++) {
            myMap.insert(make_pair(intervals[i][0], intervals[i][1]));
        }
        auto it = myMap.begin();
        int min = (*it).first;
        int max = (*it).second;

        while(it != myMap.end()) {

            if (next(it) == myMap.end()) {
                result.push_back(vector<int>{min, max});
                break;
            }

            if ((*it).first <= max) {
                max = std::max((*it).second, max);
            } else {
                result.push_back(vector<int>{min, max});
                min = (*it).first;
                max = (*it).second;
            }

            it++;
        }

        return result;
    }
};
// @lc code=end

