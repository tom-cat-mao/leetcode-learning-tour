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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         auto createSubtree = [](auto&& createSubtree, const vector<int>::iterator& preorderStart, const vector<int>::iterator& inorderStart, const vector<int>::iterator& inorderEnd) -> TreeNode* { // 定义一个递归 lambda 函数
            if (inorderStart == inorderEnd) return nullptr; // 如果中序遍历的左边界等于右边界，说明当前子树为空

            int rootValue = *preorderStart; // 获取前序遍历的第一个元素作为根节点值
            auto inOrderIterator = find(inorderStart, inorderEnd, rootValue); // 找到前序遍历的第一个元素在中序遍历中的位置
            
            TreeNode* root = new TreeNode(rootValue);
            root->left = createSubtree(createSubtree, preorderStart + 1, inorderStart, inOrderIterator); // 递归构建左子树
            root->right = createSubtree(createSubtree, preorderStart + (inOrderIterator - inorderStart) + 1, inOrderIterator + 1, inorderEnd); // 递归构建右子树

            return root; // 返回当前根节点
        };

        return createSubtree(createSubtree, preorder.begin(), inorder.begin(), inorder.end()); // 调用递归 lambda 函数，传入前序遍历的起始位置和中序遍历的起始与结束位置
    }
};
// @lc code=end

