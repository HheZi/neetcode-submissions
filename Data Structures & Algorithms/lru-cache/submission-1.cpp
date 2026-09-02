class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v, Node* p, Node* n) 
            : key(k), val(v), prev(p), next(n) {}
    };
    unordered_map<int, Node*> map;
    int capacity = 0, size = 0;
    Node *head = nullptr, *tail = nullptr;

    void moveToHead(Node* node) {
        if (node == head) return;
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (node == tail) tail = node->prev;

        node->next = head;
        node->prev = nullptr;

        if (head) head->prev = node;
        head = node;
        if (!tail) tail = head;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}
    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    int get(int key) {
        if (map[key] == nullptr) {
            return -1;
        }

        Node *node = map[key];
        moveToHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (map[key] != nullptr) {
            Node *node = map[key];
            node->val = value;
            
            moveToHead(node);

            return;
        }

        if (size == capacity) {
            map.erase(tail->key);

            Node* old_tail = tail;

            tail = tail->prev;
            if (tail) tail->next = nullptr;
            size--;

            if (old_tail == head) head = nullptr;

            delete old_tail;
        }

        Node *node = new Node(key, value, nullptr, head);

        if (!tail) tail = node;
        if (head) head->prev = node;

        map[key] = head = node;
        size++;
    }
};
