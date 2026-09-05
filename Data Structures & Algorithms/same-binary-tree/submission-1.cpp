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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        stack<pair<TreeNode*, TreeNode*>> stack;
        stack.push({p, q});

        while (!stack.empty()) {
            auto [node1, node2] = stack.top();
            stack.pop();

            if (!node1 && !node2) {
                continue;
            }

            if (node1 && node2 && node1->val == node2->val) {
                stack.push({node1->left, node2->left});
                stack.push({node1->right, node2->right});
            } else {
                return false;
            }
        }

        return true;
    }
};
