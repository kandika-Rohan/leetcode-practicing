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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

public:
    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        
        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        
        // Perform the in-order traversal to find the two nodes
        inorder(root);
        
        // Fix the swapped nodes
        if (first && last) {
            swap(first->val, last->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};
