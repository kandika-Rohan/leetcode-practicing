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
    void traversal(ListNode*head,vector<int>&ds){
        if(!head)return;
        ds.push_back(head->val);
        traversal(head->next,ds);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)return head;
        vector<int>ds;
        traversal(head,ds);
        if(ds.empty())return nullptr;
        int n=ds.size();
        vector<int>res;
        for(int i=0;i<n-1;i++){
            int a=ds[i];
            int b=ds[i+1];
            int val=__gcd(a,b);
            res.push_back(a);
            res.push_back(val);
            // res.push_back(b);
        }
        res.push_back(ds[n-1]);

        ListNode*root=new ListNode(res[0]);
        ListNode*temp=root;
        for(int i=1;i<res.size();i++){
            ListNode*ptr=new ListNode(res[i]);
            temp->next=ptr;
            temp=ptr;
        }
        return root;
    }
};