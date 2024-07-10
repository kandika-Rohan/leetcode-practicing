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
    bool f(TreeNode*root,int data){
        if(!root){
            return true;
        }
        if(root->val != data){
            return false;
        }
        if(f(root->left,data) && f(root->right,data)){
            return true;
        }
        else{
            return false;
        }
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root){
            return true;
        }
        int data=root->val;
        return f(root,data);
    }
};