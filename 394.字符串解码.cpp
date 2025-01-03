/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cctype>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<pair<int, int>> stk;
        int count = 0;

        for (char c: s) {
            if (isdigit(c)) count = 10 * count + (c - '0');
            else if (c == '[') {
                stk.push({count, ans.size()});
                count = 0;
            } else if (isalpha(c)) ans.push_back(c);
            else if (c == ']') {
                int num = stk.top().first;
                string str = ans.substr(stk.top().second, ans.size() - stk.top().second);
                for (int i = 0; i < num - 1; i++) ans.append(str);
                stk.pop();
            }
        }

        return ans;
    }

};
// @lc code=end
