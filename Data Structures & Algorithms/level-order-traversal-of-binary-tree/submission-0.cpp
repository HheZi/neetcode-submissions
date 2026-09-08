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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        queue<TreeNode*> que;
        vector<vector<int>> res;

        que.push(root);

        while(!que.empty()) {
            vector<int> vec;

            int size = que.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                
                if (!node) {
                    continue;
                }

                que.push(node->left);
                que.push(node->right);

                vec.emplace_back(node->val);
            }

            if (!vec.empty()) {
                res.emplace_back(vec);
            }
        }

        return res;
    }
};
