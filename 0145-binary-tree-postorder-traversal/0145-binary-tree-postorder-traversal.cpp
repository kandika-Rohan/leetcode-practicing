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
    void postorder(TreeNode*root,vector<int>&ds){
        if(!root)return;
        postorder(root->left,ds);
        postorder(root->right,ds);
        ds.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ds;
        postorder(root,ds);
        return ds;
    }
};