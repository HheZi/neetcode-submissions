class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> heap;

        for (int i = 0; i < k - 1; i++) {
            heap.push({nums[i], i});
        }

        for (int i = k - 1; i < nums.size(); i++) {
            heap.push({nums[i], i});
            pair<int, int> p = heap.top();

            while (p.second < i - (k - 1)) {
                heap.pop();
                if (!heap.empty()) p = heap.top();
            }
            res.push_back(p.first);
        }

        return res;
    }
};
