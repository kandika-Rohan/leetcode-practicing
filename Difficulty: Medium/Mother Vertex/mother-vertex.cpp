//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    
    void dfs1(int node,vector<int>&vis,vector<int>ajd[],stack<int>&st){
        vis[node]=1;
        for(auto it:ajd[node]){
            if(!vis[it]){
                dfs1(it,vis,ajd,st);
            }
        }
        st.push(node);
    }
    
      void dfs2(int node,vector<int>&vis,vector<int>ajd[],int &count){
        vis[node]=1;
        count++;
        for(auto it:ajd[node]){
            if(!vis[it]){
                dfs2(it,vis,ajd,count);
            }
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	   vector<int>vis(V,0);
	   
	   stack<int>st;
	   
	   for(int i=0;i<V;i++){
	       if(!vis[i]){
	           dfs1(i,vis,adj,st);
	       }
	   }
	   
	 
	 
	 int count=0;
	 vector<int>vis1(V,0);
	 
	 dfs2(st.top(),vis1,adj,count);
	 
	 if(count == V)return st.top();
	 return -1;
	   
	   
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends