//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int timer=1;
    void dfs(int node,int parent,vector<int>&low,vector<int>&timet,vector<int>&vis
    ,vector<int>adj[],vector<int>&ans){
        vis[node]=1;
        low[node]=timet[node]=timer++;
        int cnt=0;
        for(auto it:adj[node]){
            if(it == parent)continue;
            
            if(!vis[it]){
                dfs(it,node,low,timet,vis,adj,ans);
                low[node]=min(low[node],low[it]);
                 if(low[it] >= timet[node] &&  parent != -1){
                   ans[node]=1;
                 }
                 cnt++;
            }
            
            else{
                low[node]=min(low[node],timet[it]);
            }
            
        }
        if(cnt>1 && parent == -1){
            ans[node]=1;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>low(V);
        vector<int>timet(V);
        vector<int>vis(V,0);
        // memset(vis,0,sizeof vis);
        
        vector<int>ans(V,0);
        dfs(0,-1,low,timet,vis,adj,ans);
        vector<int>res;
        for(int i=0;i<V;i++){
            if(ans[i] == 1){
                res.push_back(i);
            }
        }
        if(res.size() == 0)return {-1};
        return res;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends