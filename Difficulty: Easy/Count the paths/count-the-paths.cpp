//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void dfs(int node,vector<int>&vis,vector<int>adj[],int s,int d,int &count){
        if(node == d){
            count++;
            return ;
        }
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,s,d,count);
            }
        }
        vis[node]=0;
    }
    int possible_paths(vector<vector<int>> edges, int n, int start, int destination) {
        // Code here
        
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        int count=0;
        dfs(start,vis,adj,start,destination,count);
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, s, d;
        cin >> n >> m >> s >> d;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        int ans = obj.possible_paths(edges, n, s, d);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends