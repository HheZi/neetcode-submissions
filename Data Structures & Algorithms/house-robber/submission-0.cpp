class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size(), -1);
        return dfs(nums, cache, 0);
    }

    int dfs(vector<int>& nums, vector<int>& cache, int i) {
        if (i >= nums.size()) return 0;

        if (cache[i] != -1) return cache[i];
        return cache[i] = max(nums[i] + dfs(nums, cache, i + 2), dfs(nums, cache, i + 1));
    }
};
