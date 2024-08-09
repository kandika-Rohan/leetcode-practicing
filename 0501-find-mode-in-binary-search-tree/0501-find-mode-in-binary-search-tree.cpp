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
    void inorder(TreeNode*root,unordered_map<int,int>&map){
        if(!root)return;
        inorder(root->left,map);
        map[root->val]++;
        inorder(root->right,map);
    }
    vector<int> findMode(TreeNode* root) {

        unordered_map<int,int>map;

        inorder(root,map);
        int maxi=-1;
        for(auto it:map){
            maxi=max(maxi,it.second);
        }
        vector<int>ans;
        for(auto it:map){
            int node=it.first;
            int cnt=it.second;
            if(maxi == cnt){
                ans.push_back(node);
            }
        }
        return ans;
    }
};