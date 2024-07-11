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
    void inorder(TreeNode*root,vector<int>&ds){
        if(!root){
            return;
        }
        inorder(root->left,ds);
        ds.push_back(root->val);
        inorder(root->right,ds);
    }
    void solve(TreeNode*root,vector<int>&ds,int &i){
        if(!root){
            return ;
        }
        solve(root->left,ds,i);
        if(ds[i] != root->val){
            root->val=ds[i];
        }
        i++;
        solve(root->right,ds,i);
    }
    void recoverTree(TreeNode* root) {
        vector<int>ds;
        inorder(root,ds);
        sort(ds.begin(),ds.end());
        int i=0;
        solve(root,ds,i);
    }
};