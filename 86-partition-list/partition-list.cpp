class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode less, greater;
        ListNode *a = &less, *b = &greater;

        while (head) {
            if (head->val < x) {
                a->next = head;
                a = a->next;
            } else {
                b->next = head;
                b = b->next;
            }
            head = head->next;
        }

        b->next = nullptr;
        a->next = greater.next;

        return less.next;
    }
};