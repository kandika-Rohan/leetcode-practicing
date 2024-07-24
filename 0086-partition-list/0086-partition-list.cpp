class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) {
            return head;
        }

        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        ListNode* temp = head;
        while (temp) {
            if (temp->val < x) {
                less->next = temp;
                less = temp;
            } else {
                greater->next = temp;
                greater = temp;
            }
            temp = temp->next;
        }

        greater->next = nullptr; // Terminate the greater list correctly
        less->next = greaterHead->next; // Correctly link the end of the less list to the start of the greater list

        ListNode* newHead = lessHead->next; // Correctly set the new head to the next of lessHead

        // Clean up dummy nodes to avoid memory leaks
        delete lessHead;
        delete greaterHead;

        return newHead; // Return the correct new head
    }
};
