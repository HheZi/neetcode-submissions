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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;

        while (node) {
            if ((p->val <= node->val && q->val >= node->val) ||
                (q->val <= node->val && p->val >= node->val)) {
                return node;
            } else if (p->val < node->val && q->val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        return node;
    }
};
