class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode *even = nullptr, *odd = nullptr;
        ListNode *temp1 = nullptr, *temp2 = nullptr;
        bool flag=false;
        while (head) {
            if (flag) {
                if (even == nullptr) {
                    even = head;
                    temp1 = even;
                } else {
                    temp1->next = head;
                    temp1 = head;
                }
                flag=!flag;
            } else {
                if (odd == nullptr) {
                    odd = head;
                    temp2 = odd;
                } else {
                    temp2->next = head;
                    temp2 = head;
                }
                flag=!flag;
            }
            head = head->next;
        }
        
        // Terminate the even list to avoid cycles
        if (temp1) temp1->next = nullptr;

        // Combine the odd and even lists
        if (temp2) temp2->next = even;

        return odd ? odd : even; // Return odd list, or even if odd is null
    }
};
