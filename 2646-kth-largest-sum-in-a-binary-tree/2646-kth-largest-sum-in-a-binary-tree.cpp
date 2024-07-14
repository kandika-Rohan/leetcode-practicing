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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans;
        if(!root){
            return -1;
        }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            long long sum=0;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(sum);
        }
        if(ans.size()<k){
            return -1;
        }
        sort(ans.begin(),ans.end());
        int n=ans.size();
        return ans[n-k];
    }
};