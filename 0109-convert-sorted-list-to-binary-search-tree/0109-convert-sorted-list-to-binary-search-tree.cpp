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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode*construct(vector<int>&ds,int l,int h){
        if(l>h)return nullptr;
        int mid=(l+h)/2;
        TreeNode*root=new TreeNode(ds[mid]);
        root->left=construct(ds,l,mid-1);
        root->right=construct(ds,mid+1,h);
        return root;
    }
    void solve(vector<int>&ds,ListNode*head){
        if(!head)return;
        ds.push_back(head->val);
        solve(ds,head->next);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ds;
        solve(ds,head);
        int n=ds.size();
        TreeNode*root=construct(ds,0,n-1);
        return root;
    }
};