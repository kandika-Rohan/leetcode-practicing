//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

   void dfs(int s,int d,vector<int>&vis,vector<int> adj[],int&paths)
    {
        if(s==d){
            paths++;
            return;
        }
        for(int i:adj[s])
        {
            if(!vis[i])
            {
                vis[i]=1;
                dfs(i,d,vis,adj,paths);
                vis[i]=0;
            }
        }
    }
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        vector<int>vis(V,0);
        int paths=0;
        vis[source]=1;
        dfs(source,destination,vis,adj,paths);
        return paths;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends