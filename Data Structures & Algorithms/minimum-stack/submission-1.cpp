class MinStack {
private:
    struct Node {
        int value;
        Node *next;

        Node() : value(0), next(nullptr) {}
        Node(int value) : value(value), next(nullptr) {}
        Node(int value, Node *next) : value(value), next(next) {}
        ~Node() {
            delete next;
        }
    };
    Node *node;
    stack<int> sorted_stack {};

public:
    MinStack() : node(nullptr) {}
    ~MinStack() {
        delete node;
    }
    
    void push(int val) {
        Node *new_node  = new Node(val, node);
        node = new_node;

        stack<int> stack {};

        while(!sorted_stack.empty() && sorted_stack.top() < val) {
            stack.push(sorted_stack.top());

            sorted_stack.pop();
        }

        sorted_stack.push(val);

        while(!stack.empty()) {
            sorted_stack.push(stack.top());

            stack.pop();
        }
    }
    
    void pop() {
        if (!node) {
            return;
        }

        Node *next_node = node->next;
        int val = node->value;

        node->next = nullptr;
        delete node;
        node = next_node;

        stack<int> stack {};

        while(!sorted_stack.empty() && sorted_stack.top() != val) {
            stack.push(sorted_stack.top());

            sorted_stack.pop();
        }

        if (!sorted_stack.empty()) {
            sorted_stack.pop();
        }

        while(!stack.empty()) {
            sorted_stack.push(stack.top());

            stack.pop();
        }
    }
    
    int top() {
        if (!node) {
            throw runtime_error("Stack is empty");
        }

        return node->value;
    }
    
    int getMin() {
        if (sorted_stack.empty()) {
            throw runtime_error("Stack is empty");
        }

        return sorted_stack.top();
    }
};
