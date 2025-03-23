class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int> adj[], int& cmpsize, int& edgeCount) {
        vis[node] = 1;
        cmpsize += 1;
        edgeCount += adj[node].size(); // accumulate edge count
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, cmpsize, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<int> adj[n];

        // Build adjacency list
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int cnt = 0;

        // Traverse all nodes
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int cmpsize = 0;
                int edgeCount = 0;
                // Run DFS to find component size and edge count
                dfs(i, vis, adj, cmpsize, edgeCount);
                
                edgeCount /= 2; // divide by 2 to account for double-counted edges

                // Check if component is complete
                if (edgeCount == (cmpsize * (cmpsize - 1)) / 2) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
