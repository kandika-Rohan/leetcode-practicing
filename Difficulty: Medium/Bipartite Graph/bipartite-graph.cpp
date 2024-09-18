//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int node,int col,vector<int>&color,vector<int>adj[],vector<int>
    &vis){
        vis[node]=1;
        color[node]=col;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,!col,color,adj,vis)){
                    return true;
                }
            }
            else if(color[it] == col){
                return true;
            }
        }
        return false;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int>color(V,-1);
	    
	    vector<int>vis(V,0);
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(dfs(i,1,color,adj,vis)){
	                return false;
	            }
	        }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends