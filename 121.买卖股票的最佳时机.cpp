/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        prices.emplace_back(INT16_MIN);
        deque<int> increase_deque;
        int ans = INT16_MIN;

        for (int price: prices) {
            while (!increase_deque.empty() && price < increase_deque.back()) {
                ans = max(ans, increase_deque.back() - increase_deque.front());
                increase_deque.pop_back();
            }

            increase_deque.emplace_back(price);
        }

        return ans;
    }
};
// @lc code=end

