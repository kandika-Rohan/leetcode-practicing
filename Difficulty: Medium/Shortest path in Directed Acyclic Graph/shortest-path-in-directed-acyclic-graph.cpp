//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>dist(N,1e9);
        
        vector<pair<int,int>>adj[N];
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        dist[0]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>q;
        
        q.push({0,0});
        
        while(!q.empty()){
            auto val=q.top();
            q.pop();
            int node=val.second;
            int wt=val.first;
            
            for(auto it:adj[node]){
                int adjnode=it.first;
                int weight=it.second;
                if(weight+wt < dist[adjnode]){
                    dist[adjnode]=weight+wt;
                    q.push({weight+wt,adjnode});
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i] == 1e9)dist[i]=-1;
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