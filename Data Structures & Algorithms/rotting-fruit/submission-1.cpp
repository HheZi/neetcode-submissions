class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> queue;
        int freshFruitCount = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) {
                    queue.push({1, {r, c}});
                } else if (grid[r][c] == 1) {
                    freshFruitCount++;
                }
            }
        }

        const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        while (!queue.empty()) {
            pair<int, pair<int, int>> curPair = queue.front();
            queue.pop();
            int row = curPair.second.first, col = curPair.second.second;
            int minute = curPair.first;

            for (int i = 0; i < 4; i++) {
                int r = row + dirs[i][0], c = col + dirs[i][1];

                if (min(r, c) < 0 || r == grid.size() 
                    || c == grid[0].size() || grid[r][c] != 1) {
                    continue;
                }

                res = minute;
                grid[r][c] = 2;
                freshFruitCount--;
                queue.push({minute + 1, {r,c}});
            }
        }

        return freshFruitCount > 0 ? -1 : res;
    }
};
