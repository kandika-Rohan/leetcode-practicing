

class Solution {
public:
    TreeNode* construct(vector<int>& preorder, int mini, int maxi, int& i) {
        if (i >= preorder.size()) {
            return nullptr;
        }
        if (preorder[i] < mini || preorder[i] > maxi) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = construct(preorder, mini, root->val, i);
        root->right = construct(preorder, root->val, maxi, i);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return construct(preorder, INT_MIN, INT_MAX, i);
    }
};
