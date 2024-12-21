/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto dfs = [](auto&& dfs, auto&& lP, auto&& lI, auto&& rI) {
            if (lI == rI) return (TreeNode*) nullptr;

            auto loc = find(lI, rI, *lP);

            return new TreeNode(*lP, dfs(dfs, lP + 1, lI, loc), dfs(dfs, lP + (loc - lI) + 1, loc + 1, rI));
        };

        return dfs(dfs, preorder.cbegin(), inorder.cbegin(), inorder.cend());
    }
};
// @lc code=end
