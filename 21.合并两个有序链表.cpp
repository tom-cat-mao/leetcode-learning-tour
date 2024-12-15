/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
#include <list>

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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1, *p2 = list2, *result;
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        if (p1 -> val > p2 -> val) {
            result = new ListNode(p2 -> val);
            p2 = p2 -> next;
        } else {
            result = new ListNode(p1 -> val);
            p1 = p1 -> next;
        }

        ListNode* p3 = result;

        while(p1 != nullptr && p2 != nullptr) {
            if (p1 -> val > p2 -> val) {
                p3 -> next = new ListNode(p2 -> val);
                p2 = p2 -> next;
                p3 = p3 -> next;
            } else {
                p3 -> next = new ListNode(p1 -> val);
                p1 = p1 -> next;
                p3 = p3 -> next;
            }
        }

        while (p1 != nullptr) {
            p3 -> next = new ListNode(p1 -> val);
            p1 = p1 -> next;
            p3 = p3 -> next;
        }

        while (p2 != nullptr) {
            p3 -> next = new ListNode(p2 -> val);
            p2 = p2 -> next;
            p3 = p3 -> next;
        }

        return result;
    }
};
// @lc code=end
