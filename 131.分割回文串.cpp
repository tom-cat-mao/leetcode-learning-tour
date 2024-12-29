/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int length = s.size();
        vector<vector<string>> ans;
        vector<string> path;

        // consider the input
        // it means using the first way
        // first whether it's answer
        // second skip this section
        // at last consider this section
        // if it's right or not
        auto dfs = [&](auto&& dfs, int i, int start) {
            // if get to the last
            // means find the answer
            if (i == length) {
                ans.emplace_back(path);
                return;
            }

            // skip current section and come to the next section
            if (i < length - 1) {
                dfs(dfs, i + 1, start);
            }

            // if it is palindrome
            // then put it into the answer
            // and then go to next section
            // at last reset the path
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(dfs, i + 1, i + 1);
                path.pop_back();
            }
        };

        dfs(dfs, 0, 0);
        return ans;
    }

private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right)
            if (s.at(left++) != s.at(right--)) return false;

        return true;
    }
};
// @lc code=end
