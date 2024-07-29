class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>reverseGraph[n];
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; ++i) {
            for (auto node : graph[i]) {
                reverseGraph[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Topological sort on the reversed graph
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto neighbor : reverseGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
