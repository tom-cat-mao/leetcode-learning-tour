/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
#include <iostream>

using namespace std;

class Solution {
public:
    // struct ListNode {
    //     int val;
    //     ListNode *next;
    //     ListNode(int x) : val(x), next(NULL) {}
    // };

    bool hasCycle(ListNode *head) {
        if (head == nullptr || (head -> next == nullptr)) return false;
        if (head -> next == head) return true;
        ListNode* fast = head, *slow = head;

        do {
            if (slow -> next != nullptr) slow = slow -> next;
            else return false;
            int count = 2;
            while (count > 0) {
                if (fast -> next != nullptr) fast = fast -> next;
                else return false;
                count--;
            }
        } while (slow != fast);

        return true;
    }
};
// @lc code=end
