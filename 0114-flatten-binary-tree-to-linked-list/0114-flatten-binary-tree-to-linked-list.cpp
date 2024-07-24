class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ds) {
        if (root) {
            ds.push_back(root->val);
            
            inorder(root->left, ds);
           
            inorder(root->right, ds);
        }
    }

    void flatten(TreeNode* root) {
        if (!root) return; 

        vector<int> ds;
        inorder(root, ds);

        TreeNode* Newroot = new TreeNode(ds[0]);

        TreeNode* temp = Newroot;
        for (int i = 1; i < ds.size(); i++) {
            TreeNode* curr = new TreeNode(ds[i]);
            temp->left = nullptr;
            temp->right = curr;
            temp = curr;
        }
        temp->left = nullptr;
        temp->right = nullptr;
        *root = *Newroot;
    }
};
