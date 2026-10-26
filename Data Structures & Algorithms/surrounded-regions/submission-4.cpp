class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        for (int c = 0; c < board[0].size(); c++) {
            dfs(board, 0, c);
        }
        const vector<int> columns = {0, static_cast<int>(board[0].size()) - 1};
        for (int r = 1; r < board.size() - 1; r++) {
            for (int c : columns) {
                dfs(board, r, c);
            }
        }
        for (int c = 0; c < board[0].size(); c++) {
            dfs(board, board.size() - 1, c);
        }

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (min(r, c) < 0 || r == board.size() || c == board[0].size()
            || board[r][c] != 'O') {
            return;
        }

        board[r][c] = '#';

        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};
