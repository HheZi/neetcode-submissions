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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        ListNode *last = &dummy;

        ListNode *prev = nullptr, *curr = head, *first = head;
        while (curr) {
            for (int i = 0; i < k; i++) {
                if (!curr) {
                    curr = prev;
                    prev = nullptr;
                    i = k - i;
                }

                ListNode *next = curr->next;

                curr->next = prev;

                prev = curr;
                curr = next;
            }

            last->next = prev;
            last = first;
            first = curr;
            prev = nullptr;
        }

        return dummy.next;
    }
};
