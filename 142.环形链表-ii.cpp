/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // struct ListNode {
    //     int val;
    //     ListNode *next;
    //     ListNode(int x) : val(x), next(NULL) {}
    // };
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || (head -> next == nullptr)) return nullptr;
        if (head -> next == head) return head;
        ListNode* fast = head, *slow = head;

        do {
            if (slow -> next != nullptr) slow = slow -> next;
            else return nullptr;
            int count = 2;
            while (count > 0) {
                if (fast -> next != nullptr) fast = fast -> next;
                else return nullptr;
                count--;
            }
        } while (slow != fast);

        return fast;

    }
};
// @lc code=end
