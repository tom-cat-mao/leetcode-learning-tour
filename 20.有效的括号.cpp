/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for (const char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                mystack.push(c);
            } else {
                if (mystack.empty()) return false;
                char top = mystack.top();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
                mystack.pop();
            }
        }
        return mystack.empty();
    }
};
// @lc code=end

