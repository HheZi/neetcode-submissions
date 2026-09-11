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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> queue;

        if (root) {
            queue.push(root);
        }

        vector<int> res;
        while (!queue.empty()) {
            int size = queue.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                if (i == size - 1) {
                    res.push_back(node->val);
                }

                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
        }
        return res;
    }
};
