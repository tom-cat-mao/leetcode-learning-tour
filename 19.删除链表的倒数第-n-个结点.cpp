/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> address;
        ListNode* result;
        if (head -> next == nullptr && n == 1) return nullptr;

        ListNode* ptr = head;

        while (ptr != nullptr) {
            address.push_back(ptr);
            ptr = ptr -> next;
        }

        int length = address.size();
        int ignore_num = length - n;


        if (ignore_num == 0) {
            result = new ListNode(address[1] -> val);
            ptr = result;
            for (int i = 2; i < length; i++) {
                ptr -> next = new ListNode(address[i] -> val);
                ptr = ptr -> next;
            }
            return result;
        } else {
            result = new ListNode(address[0] -> val);
            ptr = result;
        }

        for (int i = 1; i < length; i++) {
            if (i == ignore_num) continue;
            ptr -> next = new ListNode(address[i] -> val);
            ptr = ptr -> next;
        }

        return result;
    }

};

// int main () {
//     Solution s;
//     Solution::ListNode* head = new Solution::ListNode(1);
//     Solution::ListNode* ptr = head;
//     ptr -> next = new Solution::ListNode(2);
//     ptr = ptr -> next;
//     ptr -> next = new Solution::ListNode(3);
//     ptr = ptr -> next;
//     ptr -> next = new Solution::ListNode(4);
//     ptr = ptr -> next;
//     ptr -> next = new Solution::ListNode(5);
//     ptr = ptr -> next;

//     Solution::ListNode* result = s.removeNthFromEnd(head, 2);

//     while (result != nullptr) {
//         cout << result -> val << endl;
//         result = result -> next;
//     }
// }
// @lc code=end
