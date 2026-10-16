/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        Node* resNode = nullptr;

        unordered_map<int, Node*> map;
        queue<Node*> queue;

        if (node) {
            map[node->val] = resNode = new Node(node->val);
            queue.push(node);
        }

        while (!queue.empty()) {
            Node* curNode = queue.front();
            queue.pop();

            if (!map.contains(curNode->val)) {
                map[curNode->val] = new Node(curNode->val);
            }

            if (!curNode->neighbors.empty()) {
                Node* copyNode = map[curNode->val];
                for (Node* neighbor : curNode->neighbors) {
                    if (!map.contains(neighbor->val)) {
                        map[neighbor->val] = new Node(neighbor->val);
                        queue.push(neighbor);
                    }

                    copyNode->neighbors.push_back(map[neighbor->val]);
                }
            }
        }

        return resNode;
    }
};
