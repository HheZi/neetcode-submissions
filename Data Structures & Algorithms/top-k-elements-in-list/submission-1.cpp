class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map {};

        for(int i : nums) {
            map[i]++;
        }

        priority_queue<pair<int, int>> q {};
        for(auto & [key, value] : map) {
            q.push({value, key});
        }

        vector<int> res {};

        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second);
            q.pop();
        }

        return res;
    }
};
