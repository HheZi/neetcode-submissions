class Solution {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isWord;

        TrieNode() : isWord(false) {}

        void addWord(const string& word) {
            TrieNode* cur = this;
            for (char c : word) {
                if (!cur->children.count(c)) {
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->isWord = true;
        }
    };

    void dfs(vector<vector<char>>& board, int r, int c, 
    TrieNode* node, string& word, unordered_set<string>& res, vector<vector<bool>>& visit) {
        if (min(r, c) < 0 || r >= board.size() || c >= board[0].size() || visit[r][c] ||
            !node->children.count(board[r][c])) {
            return;
        }

        visit[r][c] = true;
        node = node->children[board[r][c]];
        word.push_back(board[r][c]);
        if (node->isWord) {
            res.insert(word);
        }

        dfs(board, r + 1, c, node, word, res, visit);
        dfs(board, r - 1, c, node, word, res, visit);
        dfs(board, r, c + 1, node, word, res, visit);
        dfs(board, r, c - 1, node, word, res, visit);

        word.pop_back();

        visit[r][c] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            root->addWord(word);
        }

        unordered_set<string> res;
        vector<vector<bool>> visit;
        string word = "";

        int ROWS = board.size(), COLS = board[0].size();
        visit.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                dfs(board, r, c, root, word, res, visit);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};