//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges,
    int N,int M, int src){
        
        vector<int>adj[N];
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        
        vector<int>dist(N,1e9);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>q;
        q.push({0,src});
        
        dist[src]=0;
        while(!q.empty()){
            auto val=q.top();
            q.pop();
            int wt=val.first;
            int node=val.second;
            
            for(auto it:adj[node]){
                
                if(1+wt < dist[it]){
                    dist[it]=1+wt;
                    q.push({1+wt,it});
                }
            }
        }
        
      
      
      for(int i=0;i<N;i++){
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