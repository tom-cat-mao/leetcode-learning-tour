/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2, *result;
        int count = 0, temp = 0;

        result = new ListNode(p1 -> val + p2 -> val);
        p1 = p1 -> next;
        p2 = p2 -> next;
        if (result -> val >= 10) {
            temp = result -> val % 10;
            count += (result -> val - temp) / 10;
            result -> val = temp;
        }

        ListNode* p3 = result;

        while (p1 != nullptr && p2 != nullptr) {
            p3 -> next = new ListNode(p1 -> val + p2 -> val + count);
            count = 0;
            p3 = p3 -> next;
            if (p3 -> val >= 10) {
                temp = p3 -> val % 10;
                count += (p3 -> val - temp) / 10;
                p3 -> val = temp;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }

        while (p1 != nullptr) {
            p3 -> next = new ListNode(p1 -> val + count);
            count = 0;
            p3 = p3 -> next;
            if (p3 -> val >= 10) {
                temp = p3 -> val % 10;
                count += (p3 -> val - temp) / 10;
                p3 -> val = temp;
            }
            p1 = p1 -> next;
        }

        while (p2 != nullptr) {
            p3 -> next = new ListNode(p2 -> val + count);
            count = 0;
            p3 = p3 -> next;
            if (p3 -> val >= 10) {
                temp = p3 -> val % 10;
                count += (p3 -> val - temp) / 10;
                p3 -> val = temp;
            }
            p2 = p2 -> next;
        }

        if (count != 0) {
            p3 -> next = new ListNode(count);
        }

        return result;
    }
};
// @lc code=end
