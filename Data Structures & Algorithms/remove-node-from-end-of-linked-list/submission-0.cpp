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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode *node = head;

        while (node != nullptr) {
            size++;
            node = node->next; 
        }

        ListNode *prev = nullptr, *curr = head;
        for (int i = 0; i < size - n; i++) {
            prev = curr;
            curr = curr->next;
        }

        if (prev == nullptr) {
            return head->next;
        }

        prev->next = curr->next;

        return head;
    }
};
