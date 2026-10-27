class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n, -1);
        return dfs(n, 0, cache);
    }

    int dfs(int n, int i, vector<int>& cache) {
        if (i >= n) return i == n;
        if (cache[i] != -1) return cache[i];
        return cache[i] = dfs(n, i + 1, cache) + dfs(n, i + 2, cache);
    }
};
