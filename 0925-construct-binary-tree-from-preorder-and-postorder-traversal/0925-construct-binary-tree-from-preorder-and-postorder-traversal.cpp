/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x, left, right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int prestart, int preend, vector<int>& preorder, int poststart, int postend, vector<int>& postorder,
                    unordered_map<int, int>& map) {

        if (prestart > preend || poststart > postend) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);

        if (prestart == preend) {
            return root;
        }

        int ind = map[preorder[prestart + 1]];
        int numsleft = ind - poststart + 1;

        root->left = solve(prestart + 1, prestart + numsleft, preorder, poststart, ind, postorder, map);
        root->right = solve(prestart + numsleft + 1, preend, preorder, ind + 1, postend - 1, postorder, map);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        unordered_map<int, int> map;

        for (int i = 0; i < postorder.size(); i++) {
            map[postorder[i]] = i;
        }

        TreeNode* root = solve(0, preorder.size() - 1, preorder, 0, postorder.size() - 1, postorder, map);

        return root;
    }
};
