//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    bool dfs(int node,int parent,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
              if(dfs(it,node,adj,vis)==true){
                  return true;
              }
            }
            else if(it != parent){
                return true;
            }
        }
        return false;
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(dfs(i,-1,adj,vis)==true){
	                return 1;
	            }
	        }
	    }
	    return 0;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends