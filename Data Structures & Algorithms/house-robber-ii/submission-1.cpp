class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> firstToSecondLast (nums.begin(), nums.end() - 1);
        vector<int> secondFirstToLast (nums.begin() + 1, nums.end());
        vector<int> firstCache (nums.size() - 1, -1);
        vector<int> secondCache (nums.size() - 1, -1);
    
        return max(
            dfs(firstToSecondLast, firstCache, 0), 
            dfs(secondFirstToLast, secondCache, 0)
        ); 
    }

    int dfs(vector<int>& nums, vector<int>& cache, int i) {
        if (i >= nums.size()) return 0;

        if (cache[i] != -1) return cache[i];
        return cache[i] = max(
            nums[i] + dfs(nums, cache, i + 2), 
            dfs(nums, cache, i + 1)
        );
    }
};