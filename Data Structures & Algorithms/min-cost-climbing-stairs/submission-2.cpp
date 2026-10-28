class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache (cost.size(), -1);
        return min(dfs(cost, cache, 0), dfs(cost, cache, 1));
    }

    int dfs(vector<int>& cost, vector<int>& cache, int i) {
        if (i >= cost.size()) return 0;

        if (cache[i] != -1) return cache[i];

        return cache[i] = cost[i] + min(
            dfs(cost, cache, i + 1), 
            dfs(cost, cache, i + 2)
        );
    }

};
