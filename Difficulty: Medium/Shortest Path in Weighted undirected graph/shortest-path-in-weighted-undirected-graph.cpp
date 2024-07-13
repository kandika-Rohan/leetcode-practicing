//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Because the graph is undirected
    }

    // Step 2: Initialize distance and parent arrays
    vector<int> dist(n + 1, 1e9), parent(n + 1);
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }

    // Step 3: Dijkstra's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // {distance, node}
    dist[1] = 0;

    while (!pq.empty()) {
        auto node = pq.top();
        int wt = node.first;
        int u = node.second;
        pq.pop();

        if (wt > dist[u]) continue;

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Step 4: Check if there's a path to node n
    if (dist[n] == 1e9) return {-1};

    // Step 5: Reconstruct the path from node 1 to node n
    vector<int> path;
    for (int v = n; v != 1; v = parent[v]) {
        path.push_back(v);
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    // Step 6: Insert the total weight at the beginning of the path
    path.insert(path.begin(), dist[n]);

    return path;
}

};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends