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

#include <algorithm>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<pair<TreeNode*, pair<int, int>>> stack;

        stack.push({root, {INT_MIN, INT_MAX}});

        while (!stack.empty()) {
            auto pair = stack.top();
            stack.pop();

            TreeNode* node = pair.first;
            int minV = pair.second.first, maxV = pair.second.second;

            if (node->val <= minV || node->val >= maxV)
                return false;

            if (node->right) stack.push({node->right, {node->val, maxV}});
            if (node->left) stack.push({node->left, {minV, node->val}});
        }

        return true;
    }
};