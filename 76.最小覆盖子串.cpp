/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int min_length = t.size();
        map<char, int> t_letters;
        map<char, int> substr;
        string result;
        int nmin = INT16_MAX;

        for (char& c : t) {
            t_letters[c]++;
        }


        for (int left = 0,  right = 0; right < s.size(); right++) {
            char c = s[right];
            if (t_letters.find(c) == t_letters.end()) {
                continue;
            }

            substr[c]++;


            while ((right - left + 1 >= min_length) && equalTo(t_letters, substr)) {
                int length = right - left + 1;

                if (t_letters.find(s[left]) == t_letters.end()) {
                    left++;
                    continue;
                }

                if (length < nmin /*&& equalTo(t_letters, substr)*/) {
                    nmin = length;
                    result = s.substr(left, length);
                }

                substr[s[left]]--;
                if (!substr[s[left]]) {
                    substr.erase(s[left]);
                }
                left++;
            }

        }

        return result;
    }

    bool equalTo (const map<char, int>& t, const map<char, int>& substr){
        if (t.size() != substr.size()) {
            return false;
        }

        for (const auto& pair: t) {
            if (
                substr.find(pair.first) == substr.end() || 
                substr.at(pair.first) < pair.second
               ) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

