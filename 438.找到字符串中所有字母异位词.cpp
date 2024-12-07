/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int length = p.size();
        array<int, 26> p_letters{};
        array<int, 26> s_letters{};

        for (char c : p) {
            p_letters[c - 'a']++;
        }

        for (int right = 0; right < s.size(); right++) {
            s_letters[s[right] - 'a']++;

            int left = right - length + 1;
            if (left < 0) {
                continue;
            }

            if (p_letters == s_letters) {
                result.push_back(left);
            }

            s_letters[s[left] - 'a']--;
        }


        return result;
    }
};
// @lc code=end

