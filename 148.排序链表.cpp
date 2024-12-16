/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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

    // struct ListNode {
    //     int val;
    //     ListNode *next;
    //     ListNode() : val(0), next(nullptr) {}
    //     ListNode(int x) : val(x), next(nullptr) {}
    //     ListNode(int x, ListNode *next) : val(x), next(next) {}
    // };
class Solution {
public:

    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        multiset<int> sortedlist;

        auto* ptr = head;

        while (ptr != nullptr) {
            sortedlist.insert(ptr -> val);
            ptr = ptr -> next;
        }

        ListNode* result = new ListNode();
        ptr = result;
        for (int val : sortedlist) {
            ptr -> next = new ListNode(val);
            ptr = ptr -> next;
        }

        return result -> next;
    }
};

// int main () {
//     Solution s;
//     ListNode* head = new ListNode(4);
//     head -> next = new ListNode(2);
//     head -> next -> next = new ListNode(1);
//     head -> next -> next -> next = new ListNode(3);

//     ListNode* result = s.sortList(head);

//     while (result != nullptr) {
//         cout << result -> val << " ";
//         result = result -> next;
//     }

//     return 0;
// }
// @lc code=end
