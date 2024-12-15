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
#include <cwchar>
#include <unordered_set>

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

        unordered_set<ListNode*> address;

        for (auto* ptr = head; ptr != nullptr; ptr = ptr -> next) {
            if (address.find(ptr) != address.end()) return ptr;
            address.insert(ptr);
        }

        return nullptr;
    }
};
// @lc code=end
