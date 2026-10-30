
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0); // Our starting point, because every journey needs one.
        ListNode* temp = dummy;            // Follows dummy like a loyal friend.
        int carry = 0;                     // Extra baggage from the previous addition.

        while (l1 || l2 || carry) {        // Keep working until everyone is exhausted.
            int sum = carry;              // Carry comes first, no discrimination.

            if (l1) {
                sum += l1->val;           // Add first list's digit.
                l1 = l1->next;            // Move on, no looking back.
            }

            if (l2) {
                sum += l2->val;           // Add second list's digit.
                l2 = l2->next;            // Your turn is over, next!
            }

            carry = sum / 10;             // Keep the extra digit for later.
            temp->next = new ListNode(sum % 10); // Store only the last digit.
            temp = temp->next;            // Move to the next empty seat.
        }

        return dummy->next;               // Bye dummy, we don't need you anymore.
    }
};
