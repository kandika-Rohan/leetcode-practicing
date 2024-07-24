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
    ListNode* partition(ListNode* head, int x) {
        if(!head)return nullptr;
        vector<int>list1;
        vector<int>list2;
        ListNode*temp=head;
        while(temp){
            if(temp->val < x){
                list1.push_back(temp->val);
            }
            if(temp->val >= x){
                list2.push_back(temp->val);
            }
            temp=temp->next;
        }
        for(auto it:list2){
            list1.push_back(it);
        }

        ListNode*root=new ListNode(list1[0]);
        ListNode*tmp=root;
        for(int i=1;i<list1.size();i++){
            ListNode*ptr=new ListNode(list1[i]);
            tmp->next=ptr;
            tmp=ptr;
        }
        return root;
    }
};