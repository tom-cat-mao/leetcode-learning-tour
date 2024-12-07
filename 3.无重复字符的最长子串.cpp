/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        unordered_set<char> occ;

        for (int left = 0, right = 0; right < s.size(); right++) {
            char c = s[right];

            while(occ.count(c)) {
                occ.erase(s[left]);
                left++;
            }

            occ.insert(c);
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }

};
// @lc code=end

