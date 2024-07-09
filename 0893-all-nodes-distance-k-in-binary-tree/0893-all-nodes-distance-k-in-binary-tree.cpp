/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   void makeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) {
                parentTrack[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentTrack[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        makeParent(root, parentTrack);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int currLev = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currLev == k) break;
            currLev++;
            
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();

                if (curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if (curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if  (parentTrack[curr] && !vis[parentTrack[curr]]) {
                    q.push(parentTrack[curr]);
                    vis[parentTrack[curr]] = true;
                }
            }
        }

        vector<int> res;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            res.push_back(node->val);
        }

        return res;
    }
};