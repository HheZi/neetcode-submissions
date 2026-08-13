class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> col_set{}, row_set{};

        map<pair<int, int>, unordered_set<int>> box_map {};

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                char &row = board[i][j];
                char &col = board[j][i];

                pair<int, int> box_num = {i / 3, j / 3};

                if (row_set.contains(row) 
                        || col_set.contains(col)
                        || box_map[box_num].contains(row)) {
                    return false;
                }

                if (row != '.') {
                    row_set.insert(row);
                    box_map[box_num].insert(row);
                }
                if (col != '.')
                    col_set.insert(col);
            }

            col_set.clear(); 
            row_set.clear();
        }
        return true;
    }
};
