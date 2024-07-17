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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        // Use a map to count occurrences of each value
        map<int, int> mpp;
        ListNode* temp = head;
        while (temp != nullptr) {
            mpp[temp->val]++;
            temp = temp->next;
        }

        // Create a new list excluding duplicate values
        ListNode* root = nullptr;
        ListNode* ptr = nullptr;
        temp = head;
        while (temp != nullptr) {
            if (mpp[temp->val] == 1) {  // Only include nodes with unique values
                if (!root) {
                    root = new ListNode(temp->val);
                    ptr = root;
                } else {
                    ptr->next = new ListNode(temp->val);
                    ptr = ptr->next;
                }
            }
            temp = temp->next;
        }

        return root;
    }
};
