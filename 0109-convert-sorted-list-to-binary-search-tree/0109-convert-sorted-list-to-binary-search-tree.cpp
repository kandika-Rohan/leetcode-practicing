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
    TreeNode*makeBST(int s,int e,vector<int>&ds){
        if(s>e){
            return nullptr;
        }
        int mid=s+(e-s)/2;
        TreeNode*root=new TreeNode(ds[mid]);
        root->left=makeBST(s,mid-1,ds);
        root->right=makeBST(mid+1,e,ds);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ds;
        if(head == nullptr){
            return nullptr;
        }
        ListNode*temp=head;
        while(temp){
            ds.push_back(temp->val);
            temp=temp->next;
        }
        TreeNode*root=makeBST(0,ds.size()-1,ds);
        return root;
    }
};