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
    ListNode* insertionSortList(ListNode* head) {
        vector<int>ans;
        if(!head){
            return head;
        }
        ListNode*temp=head;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        sort(ans.begin(),ans.end());

        ListNode*root=new ListNode(ans[0]);
        ListNode*tmp=root;

        for(int i=1;i<ans.size();i++){
            ListNode*ptr=new ListNode(ans[i]);

            tmp->next=ptr;
            tmp=ptr;
        }
        return root;
    }
};