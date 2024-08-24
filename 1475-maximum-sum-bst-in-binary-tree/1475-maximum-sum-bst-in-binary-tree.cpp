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

class info {
public:
    int mini;
    int maxi;
    int sum;
    bool isbst;
};

class Solution {
public:
    info solve(TreeNode* root, int &maxisum) {
        if (!root) {
            return {INT_MAX, INT_MIN, 0, true};
        }

        info left = solve(root->left, maxisum);
        info right = solve(root->right, maxisum);

        info currnode;
        currnode.sum = left.sum + right.sum + root->val; // Corrected the sum calculation
        currnode.maxi = max(root->val, right.maxi);
        currnode.mini = min(root->val, left.mini);

        if (left.isbst && right.isbst && root->val > left.maxi &&
            root->val < right.mini) { // Corrected variable names
            currnode.isbst = true;
        } else {
            currnode.isbst = false;
        }

        if (currnode.isbst) {
            maxisum = max(maxisum, currnode.sum);
        }

        return currnode;
    }

    int maxSumBST(TreeNode* root) {
        int maxisum = 0;
        info val = solve(root, maxisum); 
        return maxisum;
    }
};
