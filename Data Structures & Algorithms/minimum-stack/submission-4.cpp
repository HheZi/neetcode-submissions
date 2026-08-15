class MinStack {
private:
    struct Node {
        int value;
        int current_min;
        Node *next;

        Node() = delete;
        Node(int value, int current_min,  Node *next) 
            : value(value), current_min(current_min), next(next) {}
        ~Node() {
            delete next;
        }
    };
    Node *node;

public:
    MinStack() : node(nullptr) {}
    ~MinStack() {
        delete node;
    }
    
    void push(int val) {
        int min_value = node ? min(node->current_min, val) : val;

        Node *new_node  = new Node(val, min_value, node);
        node = new_node;
    }
    
    void pop() {
        if (!node) {
            return;
        }

        Node *next_node = node->next;

        node->next = nullptr;
        delete node;

        node = next_node;
    }
    
    int top() {
        if (!node) {
            throw runtime_error("Stack is empty");
        }

        return node->value;
    }
    
    int getMin() {
        return node->current_min;
    }
};
