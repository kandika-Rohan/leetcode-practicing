//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node,int parent,vector<int>&vis,vector<int>adj[]){
        
        vis[node]=1;
        
        for(auto it:adj[node]){
            
            if(!vis[it]){
                
                if(dfs(it,node,vis,adj)){
                    return true;
                }
            }
            else if(it != parent){
                return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<int>adj[V];
        
        for(auto it:edges){
            
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)){
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends