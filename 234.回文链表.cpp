/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
#include <cwchar>

using namespace std;

class Solution {
public:
    // struct ListNode {
    //     int val;
    //     ListNode *next;
    //     ListNode() : val(0), next(nullptr) {}
    //     ListNode(int x) : val(x), next(nullptr) {}
    //     ListNode(int x, ListNode *next) : val(x), next(next) {}
    // };

    bool isPalindrome(ListNode* head) {
        vector<int> number;
        auto* temp = head;

        while (temp != nullptr) {
            number.push_back(temp -> val);
            temp = temp -> next;
        }

        int length = number.size(), center = length / 2;

        for (int i = 0; i < center; i++)
            if (number[i] != number[length - i - 1]) return false;

        return true;
    }
};
// @lc code=end
