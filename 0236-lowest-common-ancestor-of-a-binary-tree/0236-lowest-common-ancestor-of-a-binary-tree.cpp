/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        auto left=lowestCommonAncestor(root->left,p,q);
        auto right=lowestCommonAncestor(root->right,p,q);
        if(left && right){
            return root;
        }
        if(!left && right){
            return right;
        }
        if(left && !right){
            return left;
        }
        else{
            return nullptr;
        }

        
    }
};