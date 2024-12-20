/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode* tempA = headA;
        // ListNode* tempB = headB;

        // while (tempA != nullptr) {
        //     while(tempB != nullptr) {
        //         // if (*tempA == *tempB) {
        //         if (tempA == tempB) {
        //             return tempA;
        //         }

        //         tempB = (*tempB).next;
        //     }

        //     tempA = (*tempA).next;
        //     tempB = headB;
        // }

        // return nullptr;
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode* pA = headA, *pB = headB;

        while (pA != pB) {
            pA = pA == nullptr ? headB : pA -> next;
            pB = pB == nullptr ? headA : pB -> next;
        }

        return pA;
    }
};
// @lc code=end
