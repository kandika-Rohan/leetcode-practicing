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
    int miniVal(TreeNode*root){
        if(!root){
            return -1;
        }
        TreeNode*temp=root;
        while(temp->left != nullptr){
            temp=temp->left;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }

        //we found val
        if(root->val==key){

            //case 1:no children

            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            //case:only left child

            if(root->left && !root->right){
                TreeNode*temp=root->left;
                delete root;
                return temp;
            }

            // case3:only right child
             if(!root->left && root->right){
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }

            // case4:both left and right children

            if(root->left && root->right){
                int mini=miniVal(root->right);

                // replacing with the right minimum value

                root->val=mini;

                root->right=deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val > key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else{
            root->right=deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};