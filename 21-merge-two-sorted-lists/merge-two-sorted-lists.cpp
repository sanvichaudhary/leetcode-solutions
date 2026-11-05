
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node to make joining lists easier
        ListNode dummy(0);

        // Tail keeps track of where to add the next node
        ListNode* tail = &dummy;

        // Keep comparing until one list gets exhausted
        while(list1 != NULL && list2 != NULL) {

            // Smaller value gets added first
            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next; // Move list1 forward
            }
            else {
                tail->next = list2;
                list2 = list2->next; // Move list2 forward
            }

            // Move tail to the newly added node
            tail = tail->next;
        }

        // Attach whatever is left (no need to compare again)
        if(list1 != NULL) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }

        // Return merged list, skipping the dummy node
        return dummy.next;
    }
};
