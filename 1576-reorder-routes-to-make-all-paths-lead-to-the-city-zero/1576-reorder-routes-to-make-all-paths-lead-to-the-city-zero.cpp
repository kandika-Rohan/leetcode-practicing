class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
     set<pair<int, int>>& directedEdges, int& count) {
        vis[node] = 1;

        for (auto neighbor : adj[node]) {

            if (!vis[neighbor]) {

                if (directedEdges.count({node, neighbor})) {
                    count++;
                }
                dfs(neighbor, adj, vis, directedEdges, count);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        set<pair<int, int>> directedEdges; 

        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            adj[u].push_back(v); 
            adj[v].push_back(u); 
            directedEdges.insert({u, v});
        }

        vector<int> vis(n, 0);
        int count = 0;

        dfs(0, adj, vis, directedEdges, count);

        return count;
    }
};
