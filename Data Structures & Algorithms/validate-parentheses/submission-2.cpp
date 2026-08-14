class Solution {
public:
    bool isValid(string s) {
        stack<char> stack {};
        
        for (char c : s) {
            if(!stack.empty() 
                && ((c == '}' && stack.top() == '{')
                || (c == ']' && stack.top() == '[')
                || (c == ')' && stack.top() == '('))
            ) {
                stack.pop();
            } else if(c == '{' || c == '[' || c == '(') {
                stack.push(c);
            } else {
                return false;
            }
        }

        return stack.empty();
    }
};
