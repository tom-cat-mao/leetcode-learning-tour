/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        priority_queue<int, vector<int>, greater<int>> pq;
        int v_length = lists.size(), count = 0;
        vector<ListNode*> listsptr(v_length);
        for (int i = 0; i < v_length; i++) listsptr[i] = lists[i];

        while (count < v_length) {
            count = 0;

            for (int i = 0; i < v_length; i++) {
                if (listsptr[i] == nullptr) {
                    count++;
                    continue;
                }
                pq.push(listsptr[i] -> val);
                listsptr[i] = listsptr[i] -> next;
            }
        }

        if (pq.empty()) return nullptr;

        ListNode* result = new ListNode(pq.top()), *ptr;
        pq.pop();

        ptr = result;

        while (!pq.empty()) {
            ptr -> next = new ListNode(pq.top());
            pq.pop();

            ptr = ptr -> next;
        }

        return result;
    }
};

// int main () {
//     Solution s;
//     vector<ListNode*> lists;

//     ListNode* l1 = new ListNode(1);
//     l1 -> next = new ListNode(4);
//     l1 -> next -> next = new ListNode(5);

//     ListNode* l2 = new ListNode(1);
//     l2 -> next = new ListNode(3);
//     l2 -> next -> next = new ListNode(4);

//     ListNode* l3 = new ListNode(2);
//     l3 -> next = new ListNode(6);

//     lists.push_back(l1);
//     lists.push_back(l2);
//     lists.push_back(l3);

//     ListNode* result = s.mergeKLists(lists);

//     while (result != nullptr) {
//         cout << result -> val << " ";
//         result = result -> next;
//     }

//     return 0;
// }
// @lc code=end
