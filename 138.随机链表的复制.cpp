/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <bits/stdc++.h>

using namespace std;

// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;

//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        vector<Node*> address;
        for (auto* ptr = head; ptr != nullptr; ptr = ptr -> next) address.push_back(ptr);
        int length = address.size();
        vector<int> r_pointto;
        vector<Node*> result_vec;

        for (auto* ptr : address) {
            auto it = find(address.begin(), address.end(), ptr -> random);

            if (it != address.end()) {
                r_pointto.push_back(distance(address.begin(), it));
            } else {
                r_pointto.push_back(-1);
            }
        }

        for (auto* ptr = head; ptr != nullptr; ptr = ptr -> next) {
            result_vec.push_back(
                new Node(ptr -> val)
            );
        }

        for (int i = 0; i < length; i++) {
            if (r_pointto[i] != -1) result_vec[i] -> random = result_vec[r_pointto[i]];
            else result_vec[i] -> random = nullptr;

            if (i + 1 < length) result_vec[i] -> next = result_vec[i + 1];
            else result_vec[i] -> next = nullptr;
        }


        Node* r = result_vec[0];
        return r;
    }
};

// int main () {
//     Solution s;
//     Node* head = new Node(7);
//     head -> next = new Node(13);
//     head -> next -> next = new Node(11);
//     head -> next -> next -> next = new Node(10);
//     head -> next -> next -> next -> next = new Node(1);

//     head -> next -> random = head;
//     head -> next -> next -> random = head -> next -> next -> next -> next;
//     head -> next -> next -> next -> random = head -> next -> next;
//     head -> next -> next -> next -> next -> random = head;

//     Node* result = s.copyRandomList(head);
//     return 0;
// }
// @lc code=end
