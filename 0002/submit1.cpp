// Results:
// Elapsed time: 40ms | Beats 5.10% at the submit time
// Memory: 77.42MB | Beats 75.46% at the submit time

// Code Complexity:
// O(n) time complexity
// O(n) space complexity

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
        ListNode* head = nullptr;
        ListNode* currentNode = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int l1Val = l1 == nullptr ? 0 : l1->val;
            int l2Val = l2 == nullptr ? 0 : l2->val;

            int currentValue = l1Val + l2Val + carry;
            int digit = currentValue % 10;
            carry = currentValue / 10;

            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;

            if (currentNode == nullptr) {
                currentNode = new ListNode(digit);
                head = currentNode;
            } else {
                currentNode->next = new ListNode(digit);
                currentNode = currentNode->next;
            }
        }

        if (carry > 0) {
            currentNode->next = new ListNode(carry);
        }

        return head;
    }
};
