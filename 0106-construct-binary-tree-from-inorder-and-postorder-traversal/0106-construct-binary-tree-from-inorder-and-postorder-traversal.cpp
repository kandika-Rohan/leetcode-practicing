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
    TreeNode* helper(int postStart, int postEnd, vector<int>& postorder, int instart, int inend, vector<int>& inorder, unordered_map<int, int>& mpp) {
        if (instart > inend || postStart > postEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]); // Fix: Initialize root with postorder[postEnd]
        int inroot = mpp[root->val];
        int numsleft = inroot - instart;

        root->left = helper(postStart, postStart + numsleft - 1, postorder, instart, inroot - 1, inorder, mpp); // Fix: Correct indices
        root->right = helper(postStart + numsleft, postEnd - 1, postorder, inroot + 1, inend, inorder, mpp); // Fix: Correct indices and pass mpp

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = helper(0, postorder.size() - 1, postorder, 0, inorder.size() - 1, inorder, mpp);
        return root;
    }
};
