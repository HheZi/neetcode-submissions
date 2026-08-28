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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *node = &dummy;

        int sum = 0, rest = 0;
        while (l1 || l2 || rest) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;

            sum = v1 + v2 + rest;
            rest = sum / 10;

            node = node->next = new ListNode(sum % 10);
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        node->next = l1 ? l1 : (l2 ? l2 : nullptr);

        return dummy.next;
    }
};
