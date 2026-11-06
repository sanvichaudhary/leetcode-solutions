
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while (temp != NULL) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            tail->next = new ListNode(pq.top());
            pq.pop();

            tail = tail->next;
        }

        return dummy->next;
    }
};
