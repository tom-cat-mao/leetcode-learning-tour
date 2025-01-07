/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Custom comparator for min heap based on frequency
        auto comp = [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        unordered_map<int,int> countMap;
        vector<int> ans;
        
        // Count frequencies
        for (const int num : nums) {
            countMap[num]++;
        }
        
        // Maintain k elements in min heap
        for (const auto& [num, freq] : countMap) {
            pq.push({num, freq});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // Extract k elements from heap
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
