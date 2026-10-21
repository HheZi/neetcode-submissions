class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() > board.size() * board[0].size()) return false;

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == word[0] && dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i) {
        if (min(r, c) < 0 || r == board.size() || c == board[0].size() || i == word.size() ||
            board[r][c] != word[i]) {
            return false;
        }

        if (i == word.size() - 1) {
            return true;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        i++;
        if (dfs(board, word, r + 1, c, i) || dfs(board, word, r - 1, c, i) ||
            dfs(board, word, r, c + 1, i) || dfs(board, word, r, c - 1, i)) {
            board[r][c] = temp;
            return true;
        }

        board[r][c] = temp;

        return false;
    }
};
