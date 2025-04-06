//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node,vector<int>&vis,vector<int>&pathVis,
    vector<int>adj[]){
        
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it:adj[node]){
            
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<int>adj[V];
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends