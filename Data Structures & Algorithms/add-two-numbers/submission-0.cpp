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
        while (l1 && l2) {
            sum = l1->val + l2->val + rest;
            rest = sum / 10;

            node = node->next = new ListNode(sum % 10);
            l1 = l1->next;
            l2 = l2->next;
        }

        while (rest > 0) {
            if (l1 || l2) {
                ListNode *rest_node = l1 ? l1 : l2;

                sum = rest_node->val + rest;
                rest = sum / 10;

                node = node->next = new ListNode(sum % 10);
                l1 = l1 ? l1->next : nullptr;
                l2 = l2 ? l2->next : nullptr;
            } else {
                node = node->next = new ListNode(rest);
                rest = 0;
            }
        }

        node->next = l1 ? l1 : (l2 ? l2 : nullptr);

        return dummy.next;
    }
};
