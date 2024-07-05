class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }

        int minDistance = INT_MAX;
        int maxDistance = INT_MIN;
        int firstCP = -1;
        int prevCP = -1;
        int index = 1; // Start from the second node
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        while (next != nullptr) {
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (firstCP == -1) {
                    firstCP = index;
                } else {
                    minDistance = min(minDistance, index - prevCP);
                    maxDistance = max(maxDistance, index - firstCP);
                }
                prevCP = index;
            }
            prev = curr;
            curr = next;
            next = next->next;
            ++index;
        }

        if (minDistance == INT_MAX || maxDistance == INT_MIN) {
            return {-1, -1};
        }
        return {minDistance, maxDistance};
    }
};
