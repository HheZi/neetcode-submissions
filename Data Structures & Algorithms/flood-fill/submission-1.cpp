class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        if (originalColor != color ) {
            ROWS = image.size();
            COLS = image[0].size();
            dfs(image, sr, sc, color, image[sr][sc]);
        }

        return image;
    }
private:
    int ROWS, COLS;
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int originalColor) {
        
        if (min(sr, sc) < 0 || sr == ROWS || sc == COLS || image[sr][sc] != originalColor) {
            return;
        }

        image[sr][sc] = color;

        dfs(image, sr + 1, sc, color, originalColor);
        dfs(image, sr - 1, sc, color, originalColor);
        dfs(image, sr, sc + 1, color, originalColor);
        dfs(image, sr, sc - 1, color, originalColor);
    }
};