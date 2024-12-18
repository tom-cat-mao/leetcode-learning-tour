/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
                return 0;
            }

            int max_diameter = 0;

            function<int(TreeNode*)> depth = [&](TreeNode* node) -> int {
                if (node == nullptr) {
                    return 0;
                }

                int left_depth = depth(node->left);
                int right_depth = depth(node->right);

                // 更新最大直径
                max_diameter = max(max_diameter, left_depth + right_depth);

                return max(left_depth, right_depth) + 1;
            };

            depth(root);
            return max_diameter;
    }
};
// @lc code=end
