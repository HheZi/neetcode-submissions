class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size()); 
        stack<pair<int, int>> stack {};

        for (int i = 0; i < temperatures.size(); i++) {
            int temp = temperatures[i];

            while (!stack.empty() && temp > stack.top().first) {
                int index = stack.top().second;
                stack.pop();
                res[index] = i - index;
            }
            stack.push({temp, i});
        }
        return res;
    }
};
