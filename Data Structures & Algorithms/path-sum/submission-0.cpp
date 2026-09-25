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
    bool dfs(TreeNode* root, int targetSum, int sum) {
        if (!root) {
            return false;
        }

        sum += root->val;
        
        if (!root->left && !root->right && targetSum == sum) {
            return true;
        }

        return dfs(root->left, targetSum, sum) 
            || dfs(root->right, targetSum, sum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};