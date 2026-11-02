class Solution {
   public:
    int numDecodings(string s) {
        unordered_map<int, int> cache;
        cache[s.size()] = 1;

        return dfs(s, 0, cache); 
    }

    int dfs(string& s, int i, unordered_map<int, int>& cache) {
        if (cache.contains(i)) return cache[i];
        if (s[i] == '0') return 0;

        int res = dfs(s, i + 1, cache);
        if (i < s.size() - 1) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')) {
                res += dfs(s, i + 2, cache);
            }
        }
        cache[i] = res;
        return res;
    }
};
