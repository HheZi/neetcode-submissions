/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* node = &dummy;

        unordered_map<Node*, Node*> map;

        while (head) {
            if (!map[head]) {
                map[head] = new Node(head->val);
            }
            node->next = map[head];

            if (head->random) {
                if (!map[head->random]) {
                    map[head->random] = new Node(head->random->val);
                }
                node->next->random = map[head->random];
            }

            node = node->next;
            head = head->next;
        }

        return dummy.next;
    }
};
