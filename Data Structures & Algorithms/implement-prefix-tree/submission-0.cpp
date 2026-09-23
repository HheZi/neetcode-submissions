class PrefixTree {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isWord = false;
    };
    TrieNode root;
public:
    PrefixTree() {}
    
    void insert(string word) {
        TrieNode *curr = &root;
        for (char c : word) {
            if (!curr->children.contains(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *curr = &root;

        for (char c : word) {
            if (!curr->children.contains(c)) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = &root;

        for (char c : prefix) {
            if (!curr->children.contains(c)) {
                return false;
            }
            curr = curr->children[c];
        }

        return true;
    }
};
