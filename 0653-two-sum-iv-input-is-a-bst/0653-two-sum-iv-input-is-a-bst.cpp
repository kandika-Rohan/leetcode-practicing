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
    void inorder(TreeNode*root,vector<int>&in){
        if(root){
            inorder(root->left,in);
            in.push_back(root->val);
            inorder(root->right,in);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>in;
        inorder(root,in);

        int i=0;
        int j=in.size()-1;
        while(i<j){
            int sum=in[i]+in[j];
            if(sum==k){
                return true;
            }
            if(sum > k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};