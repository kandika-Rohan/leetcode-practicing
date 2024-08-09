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
    int maxLevelSum(TreeNode* root) {
        if(!root)return 0;

        int maxi=INT_MIN;

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=-1;
        int level=0;
        while(!q.empty()){
            int sum =0;
            int n=q.size();
            level++;
            for(int i=0;i<n;i++){
                auto val=q.front();
                q.pop();
               auto node=val.first;
                sum += node->val;
                int l=val.second;
                if(node->left)q.push({node->left,l++});
                if(node->right)q.push({node->right,l++});

            }
            if(maxi<sum){
                maxi=sum;
                ans=level;
            }
        }
        return ans;
    }
};