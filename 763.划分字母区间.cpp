/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        int length = s.size();
        for (int i = 0; i < length; i++) {
            last.at(s.at(i) - 'a') = i; // 找到最后一个位置
        }

        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last.at(s.at(i) - 'a')); // 更新得到当前区间右端点的最大值
            if (end == i) { // 闭合区间确定
                ans.emplace_back(end - start + 1);  // 把当前区间长度放入答案
                start = i + 1; // 到下一个位置
            }
        }

        return ans;
    }
};
// @lc code=end

