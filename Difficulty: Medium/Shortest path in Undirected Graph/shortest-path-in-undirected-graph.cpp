//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        // code here
        
        vector<int>adj[n];
        
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>dist(n,1e9);
        queue<pair<int,int>>q;
        q.push({0,src});
        dist[src]=0;
        // vector<int>vis(n,0);
        // vis[src]=1;
        while(!q.empty()){
            
            auto val=q.front();
            q.pop();
            
            int d=val.first;
            int node=val.second;
            
            for(auto it:adj[node]){
                if(1+d < dist[it]){
                    dist[it]=1+d;
                    q.push({1+d,it});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dist[i] == 1e9){
                dist[i]=-1;
            }
        }
        
        return dist;
    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends