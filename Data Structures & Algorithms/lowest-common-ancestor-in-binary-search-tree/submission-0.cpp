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
    bool isDescender(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return false;
        }

        if (root->val == p->val || root->val == q->val) {
            return true;
        }

        return isDescender(root->left, p, q) || isDescender(root->right, p, q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }
        
        bool isRootLca = root->val == p->val || root->val == q->val;

        bool isLeft = isDescender(root->left, p, q);
        bool isRight = isDescender(root->right, p, q);

        if ((isLeft && isRight) || isRootLca) {
            return root;
        } else if (isLeft) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};
