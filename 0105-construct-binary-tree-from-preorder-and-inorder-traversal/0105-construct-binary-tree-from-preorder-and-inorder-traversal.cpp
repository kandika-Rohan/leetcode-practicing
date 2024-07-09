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
  TreeNode* helper(int prestart,int preend,vector<int>&preorder,int instart,
  int inend,vector<int>&inorder,unordered_map<int,int>&mpp){
    if(prestart>preend || instart>inend){
        return nullptr;
    }
    TreeNode*root=new TreeNode(preorder[prestart]);
    int inroot=mpp[root->val]; //postion where the element present in the inorder 
    int numleft=inroot-instart;

    root->left=helper(prestart+1,prestart+numleft,preorder,instart,inroot-1,inorder,mpp);
    root->right=helper(prestart+numleft+1,preend,preorder,inroot+1,inend,inorder,mpp);
    return root;


  }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }

        TreeNode*root=helper(0,preorder.size()-1,preorder,0,inorder.size()-1,inorder,mpp);
        return root;
    }
};