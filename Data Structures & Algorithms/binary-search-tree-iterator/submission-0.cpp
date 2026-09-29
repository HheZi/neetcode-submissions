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
class BSTIterator {
    vector<int> vec;
    int index = 0;
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* node = root;

        while (node || !stack.empty()) {
            while (node) {
                stack.push(node);
                node = node->left;
            }

            node = stack.top();
            stack.pop();
            vec.push_back(node->val);
            node = node->right;
        }
    }

    int next() {
        return vec[index++];
    }

    bool hasNext() { 
        return index < vec.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */