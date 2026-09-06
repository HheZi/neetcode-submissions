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
    bool subtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }

        if (root && subRoot && root->val == subRoot->val) {
            bool isSubtreeLeft = subtree(root->left, subRoot->left);
            bool isSubtreeRight = subtree(root->right, subRoot->right);

            return isSubtreeLeft && isSubtreeRight;
        } 

        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if ((!root && subRoot) || (root && !subRoot)) {
            return false;
        }

        if (root->val == subRoot->val && subtree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
