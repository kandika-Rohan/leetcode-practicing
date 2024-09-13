//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int tm=1;
    void dfs(int node,int parent,vector<int>&vis,
    vector<int>adj[],vector<int>&low,vector<int>&timeI
    ,vector<vector<int>>&bridges){
        vis[node]=1;
        timeI[node]=low[node]=tm;
        tm++;
        for(auto it:adj[node]){
            if(it == parent)continue;
            
            if(!vis[it]){
                dfs(it,node,vis,adj,low,timeI,bridges);
            }
            
            low[node]=min(low[node],low[it]);
            
            if(low[it]>timeI[node]){
                bridges.push_back({min(it,node),max(it,node)});
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    vector<int>vis(V,0),low(V,0),timeI(V,0);
	    vector<vector<int>>bridges;
	    dfs(0,-1,vis,adj,low,timeI,bridges);
	    sort(bridges.begin(),bridges.end());
	    return bridges;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends