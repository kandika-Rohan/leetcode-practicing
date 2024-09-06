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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
         if (head == nullptr) {
        return nullptr;
    }

    std::set<int> st(nums.begin(), nums.end());
    ListNode* dummy = new ListNode(0); // Create a dummy node
    dummy->next = head;
    ListNode* temp = dummy;

    while (temp->next != nullptr) {
        int val = temp->next->val;
        if (st.find(val) != st.end()) {
            ListNode* ptr = temp->next;
            temp->next = temp->next->next;
            delete ptr;
        } else {
            temp = temp->next;
        }
    }

    ListNode* new_head = dummy->next;
    delete dummy;
    return new_head;
    }
};