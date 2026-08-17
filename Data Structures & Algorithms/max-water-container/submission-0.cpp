class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0, end = heights.size() - 1;

        int val = 0;
        while (start < end) {
            val = max(val, (end - start) * min(heights[start], heights[end]));

            if (heights[start] <= heights[end]) {
                start++;
            } else {
                end--;
            }
        }

        return val;
    }
};
