/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string one_way_stack;
        getnext(one_way_stack, n, n);
        return result;
    }

private:
    pair<char, char> quote{'(', ')'};
    vector<string> result;

    void getnext(string& one_way_stack, int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(one_way_stack);
            return;
        }

        if (left > 0) {
            one_way_stack.push_back(quote.first);
            getnext(one_way_stack, left - 1, right);
            one_way_stack.pop_back();
        }

        if (right > left) {
            one_way_stack.push_back(quote.second);
            getnext(one_way_stack, left, right - 1);
            one_way_stack.pop_back();
        }
    }
};
// @lc code=end

