/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

    ListNode* reverseList(ListNode* head) {
        vector<ListNode*> nodevector;
        int length;
        auto* temp = head;
        ListNode* result;

        if (head == nullptr) {
            return nullptr;
        }

        while (temp != nullptr) {
            nodevector.push_back(temp);
            temp = temp -> next;
        }

        reverse(nodevector.begin(), nodevector.end());

        result = new ListNode(nodevector[0] -> val);

        temp = result;
        length = nodevector.size();

        for (int i = 1; i < length; i++) {
            temp -> next = new ListNode(nodevector[i] -> val);
            temp = temp -> next;
        }

        return result;
    }
};
// @lc code=end
