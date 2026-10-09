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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> st;
        vector<int> res;

        st.push({root, false});

        while (!st.empty()) {
            auto [node, isVisited] = st.top();
            st.pop();

            if (node) {
                if (isVisited) {
                    res.push_back(node->val);
                } else {
                    st.push({node, true});
                    st.push({node->right, false});
                    st.push({node->left, false});
                }
            }
        }

        return res;
    }
};