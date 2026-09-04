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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> stack;

        if (root) {
            stack.push({root, 1});
        }

        int res = 0;
        while (!stack.empty()) {
            auto pair = stack.top();
            stack.pop();

            TreeNode *node = pair.first;
            int depth = pair.second;
            
            res = max(res, depth);
            if (node->left) stack.push({node->left, depth + 1});
            if (node->right) stack.push({node->right, depth + 1});
        }
        return res;
    }
};
