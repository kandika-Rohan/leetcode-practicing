//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> eventualSafeNodes(int V, std::vector<int> adj[]) {
        std::vector<std::vector<int>> reverseAdj(V);
        std::vector<int> indegree(V, 0);
        
        // Create reverse graph and compute indegrees
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                reverseAdj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        std::queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        std::vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : reverseAdj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        std::sort(ans.begin(), ans.end());
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends