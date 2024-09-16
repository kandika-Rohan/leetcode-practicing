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
    void traversal(ListNode* head, vector<int>& ds) {
        if (!head) return;
        ds.push_back(head->val); // Store the values of the linked list in the vector
        traversal(head->next, ds);
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        vector<int> ds;
        traversal(head, ds);  // Fill the vector with the linked list's values

        int i = 0;
        int j = ds.size() - 1;
        ListNode* temp = head;

        // Reordering the linked list according to the algorithm
        while (i < j) {
            temp->val = ds[i++]; // Set value from the front of the vector
            temp = temp->next;
            temp->val = ds[j--]; // Set value from the back of the vector
            temp = temp->next;
        }
        if (i == j) temp->val = ds[i]; // Handle the middle element in case of an odd-length list

        return;
    }
};
