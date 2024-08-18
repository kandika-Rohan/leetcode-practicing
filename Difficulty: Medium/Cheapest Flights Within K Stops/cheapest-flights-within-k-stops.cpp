//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights,
    int src, int dst, int k)  {
        // Code here
        
        vector<pair<int,int>>adj[n];
        
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
        
        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto val=q.front();
            q.pop();
            int steps=val.first;
            int cost=val.second.second;
            int node=val.second.first;
            if(steps > k)continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int ct=it.second;
                if(steps<=k && ct+cost < dist[adjnode] ){
                    dist[adjnode]=ct+cost;
                    q.push({steps+1,{adjnode,ct+cost}});
                }
            }
        }
        
        if(dist[dst] != 1e9)return dist[dst];
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends