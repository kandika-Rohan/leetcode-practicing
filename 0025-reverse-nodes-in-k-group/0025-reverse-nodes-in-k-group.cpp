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

    void solve(ListNode* head, vector<int>& ds) {
        while (head) {
            ds.push_back(head->val);
            head = head->next;
        }
    }

    
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> ds;
        solve(head, ds);

     
        for (int i = 0; i + k <= ds.size(); i += k) {
            reverse(ds.begin() + i, ds.begin() + i + k);
        }

        ListNode* newHead = new ListNode(0);
        ListNode* current = newHead;
        
        for (int val : ds) {
            current->next = new ListNode(val);
            current = current->next;
        }

        return newHead->next; 
    }
};
