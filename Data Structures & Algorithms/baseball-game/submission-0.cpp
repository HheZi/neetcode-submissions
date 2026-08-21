class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack{};

        for (string &operation : operations) {
            if (operation == "+") {
                int r = stack.top();
                stack.pop();
                int l = stack.top();
                stack.pop();

                stack.push(l);
                stack.push(r);
                stack.push(l + r);
            } else if (operation == "D") {
                int num = stack.top();
                stack.pop();

                stack.push(num);
                stack.push(2 * num);
            } else if (operation == "C") {
                stack.pop();
            } else {
                stack.push(stoi(operation));
            }
        }

        int total = 0;

        while (!stack.empty()) {
            total += stack.top();
            stack.pop();
        }

        return total;
    }
};