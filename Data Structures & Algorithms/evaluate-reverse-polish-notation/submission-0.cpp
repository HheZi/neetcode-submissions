class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack {};

        for (string &token: tokens) {
            if(isDigit(token)) {
                stack.push(stoi(token));
            } else {
                int right = stack.top();
                stack.pop();

                int left = stack.top();
                stack.pop();

                if(token == "+") {
                    stack.push(left + right);
                } else if (token == "-") {
                    stack.push(left - right);
                } else if (token == "*") {
                    stack.push(left * right);
                }   else {
                        stack.push(left / right);
                }
            }
        }

        return stack.top();
    }

    bool isDigit(string &str) {
        if (str == "+" || str == "-" || str == "*" || str == "/") return false;
        return true;
    }
};
