/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);

        for (ListNode* list : lists) {
            if (list) {
                heap.push(list);
            }
        }

        ListNode dummy;
        ListNode* current = &dummy;
        while (!heap.empty()) {
            ListNode* node = heap.top();
            heap.pop();
            current = current->next = node;

            node = node->next;
            if (node) {
                heap.push(node);
            }
        }
        return dummy.next;
    }
};
