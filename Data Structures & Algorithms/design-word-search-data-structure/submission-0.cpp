struct TrieNode {
    vector<TrieNode*> children;
    bool isWord;

    TrieNode(): children(26, nullptr), isWord(false) {}
};

class WordDictionary {
   private:
    TrieNode root;

    bool dfs(TrieNode *node, string &word, int index) {
        TrieNode *curr = node;

        for (int i = index; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (TrieNode *child : curr->children) {
                    if (child && dfs(child, word, i + 1)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (!curr->children[c - 'a']) {
                    return false;
                }
                curr = curr->children[c - 'a'];
            }
        }

        return curr->isWord;
    }
   public:
    WordDictionary() {}

    void addWord(string word) {
        TrieNode* curr = &root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }

    bool search(string& word) {
        return dfs(&root, word, 0);
    }
};
