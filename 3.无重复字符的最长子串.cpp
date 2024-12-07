/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> man_made_queue;
    }

    int is_copied(const vector<char>& str, vector<char>& result, int i) {
        int j, k;
        for (
            j = i, k = 0; 
            str[j] == result[k] && j < result.size(); 
            j++, k++ 
            );

        return j;
    }
};
// @lc code=end

