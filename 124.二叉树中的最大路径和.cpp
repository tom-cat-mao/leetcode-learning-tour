/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int max = INT_MIN;

    int maxPathSum(TreeNode* root) {
        rootSum(root);
        return max;
    }

    int rootSum(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftSum = std::max(rootSum(root -> left), 0); // 求左侧的最大值
        int rightSum = std::max(rootSum(root -> right), 0); // 求右侧最大值

        int subsum = root -> val + leftSum + rightSum; // 当前最大值，即将左侧和右侧最大和自身加起来得到

        max = std::max(subsum, max); //更新max

        return root -> val + std::max(leftSum, rightSum); // 返回当前值加两侧最大的一个
    }

};

// @lc code=end
