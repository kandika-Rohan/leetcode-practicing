//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        
        vector<int>dist(n,1e9);
        
        vector<pair<int,int>>adj[n];
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>q;
        q.push({0,0});
        dist[0]=0;
        
        while(!q.empty()){
            auto val=q.top();
            q.pop();
            int wt=val.first;
            int u=val.second;
            for(auto it:adj[u]){
                int v=it.first;
                int weight=it.second;
                if(weight+wt < dist[v]){
                    dist[v]=weight+wt;
                    q.push({wt+weight,v});
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends