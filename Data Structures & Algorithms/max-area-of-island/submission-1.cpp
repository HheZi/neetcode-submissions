class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    res = max(res, dfs(grid, r, c));
                }
            }
        }

        return res;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (min(r, c) < 0 || r == grid.size() 
            || c == grid[0].size() || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        int res = 1;
        res += dfs(grid, r + 1, c);
        res += dfs(grid, r - 1, c);
        res += dfs(grid, r, c + 1);
        res += dfs(grid, r, c - 1);
        
        return res;
    }
};
