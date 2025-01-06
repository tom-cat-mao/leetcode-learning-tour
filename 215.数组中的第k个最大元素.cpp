/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> pq(nums.size(), INT_MIN);
        int pq_size = 0;

        // Build max heap
        for (int num : nums) {
            pq[pq_size] = num;
            int i = pq_size;
            
            // Bubble up
            while (i > 0) {
                int parent = (i - 1) / 2;
                if (pq[parent] < pq[i]) {
                    swap(pq[parent], pq[i]);
                    i = parent;
                } else {
                    break;
                }
            }
            pq_size++;
        }

        // Extract k times
        int ans = 0;
        while (k > 0) {
            ans = pq[0];
            pq[0] = pq[pq_size - 1];
            pq[pq_size - 1] = INT_MIN;
            pq_size--;

            // Heapify down
            int i = 0;
            while (true) {
                int largest = i;
                int left = 2 * i + 1;
                int right = 2 * i + 2;

                if (left < pq_size && pq[left] > pq[largest])
                    largest = left;
                if (right < pq_size && pq[right] > pq[largest])
                    largest = right;

                if (largest != i) {
                    swap(pq[i], pq[largest]);
                    i = largest;
                } else {
                    break;
                }
            }
            k--;
        }
        return ans;
    }
};
// @lc code=end

