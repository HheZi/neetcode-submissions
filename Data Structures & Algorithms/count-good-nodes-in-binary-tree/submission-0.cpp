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
    int goodNodes(TreeNode* root) {
        stack<pair<TreeNode*, int>> stack;
        
        stack.push({root, root->val});

        int res = 0;
        while(!stack.empty()) {
            auto [node, maxVal] = stack.top();
            stack.pop();

            if (node) {
                if (maxVal <= node->val) {
                    res++;
                }

                stack.push({node->right, max(maxVal, node->val)});
                stack.push({node->left, max(maxVal, node->val)});
            }
        }

        return res;
    }
};
