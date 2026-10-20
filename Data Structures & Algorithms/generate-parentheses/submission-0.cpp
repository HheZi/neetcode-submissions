class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(res, stack, 0, 0, n);

        return res;
    }

    void backtrack(vector<string>& res, string& stack, int open, int close, int n) {
        if (open == close && open == n) {
            res.push_back(stack);
            return;
        }

        if (open < n) {
            stack += '(';
            backtrack(res, stack, open + 1, close, n);
            stack.pop_back();
        }

        if (close < open) {
            stack += ')';
            backtrack(res, stack, open, close + 1, n);
            stack.pop_back();
        }
    }
};
