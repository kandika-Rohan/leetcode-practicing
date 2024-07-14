class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector<int> vec;
            while (len--) {
                root = q.front();
                q.pop();
                vec.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            unordered_map<int, int> map;
            for (int i=0; i<vec.size(); i++) map[vec[i]] = i;
            sort(vec.begin(), vec.end());
            int i=0;
            while (i < vec.size()) {
                if (map[vec[i]] != i) {
                    swap(vec[i], vec[map[vec[i]]]);
                    ans++;
                }
                else i++;
            }
        }
        return ans;
    }
};