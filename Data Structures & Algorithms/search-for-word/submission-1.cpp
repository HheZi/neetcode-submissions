class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<int, unordered_set<int>> visits;
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, visits, word, r, c, 0)) {
                        return true;
                    }
                    visits.clear();
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, unordered_map<int, unordered_set<int>>& visits,
             string& word, int r, int c, int i) {
        if (min(r, c) < 0 || r == board.size() || c == board[0].size() || i == word.size() ||
            visits[r].contains(c) || board[r][c] != word[i]) {
            return false;
        }

        if (i == word.size() - 1) {
            return true;
        }

        visits[r].insert(c);

        i++;
        if (dfs(board, visits, word, r + 1, c, i) || dfs(board, visits, word, r - 1, c, i) ||
               dfs(board, visits, word, r, c + 1, i) || dfs(board, visits, word, r, c - 1, i)) {
            return true;
        }

        visits[r].erase(c);

        return false;
    }
};
