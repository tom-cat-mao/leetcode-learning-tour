/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;

        ListNode* current;
        ListNode* ptr;
        vector<ListNode*> address;

        for (int i = 0; i < k; i++) {
            if (head == nullptr) break;
            address.push_back(head);
            head = head -> next;
        }

        int length = address.size();
        if (length == k) address[0] -> next = reverseKGroup(address[length - 1] -> next, k);
        else return address[0];

        current = address[length - 1];
        ptr = current;
        for (int i = length - 2; i > -1; i--) {
            ptr -> next = address[i];
            ptr = ptr -> next;
        }

        return current;
    }
};

// int main () {
//     Solution solution;
//     Solution::ListNode* head = new Solution::ListNode(1);
//     Solution::ListNode* ptr = head;
//     for (int i = 2; i < 6; i++) {
//         ptr -> next = new Solution::ListNode(i);
//         ptr = ptr -> next;
//     }

//     Solution::ListNode* result = solution.reverseKGroup(head, 3);
//     while (result != nullptr) {
//         cout << result -> val << " ";
//         result = result -> next;
//     }
// }

// @lc code=end
