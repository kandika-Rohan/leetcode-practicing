//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class DisjointSet{
   vector<int>parent,rank,size;
   public:
   DisjointSet(int n){
       parent.resize(n+1);
       rank.resize(n+1);
       size.resize(n+1);
       
       for(int i=0;i<=n;i++){
           parent[i]=i;
           size[i]=1;
       }
   }
   
   int findparent(int x){
       if(parent[x] == x)return x;
       else{
           return parent[x]=findparent(parent[x]);
       }
   }
   
   void unionfindrank(int u,int v){
       
       int x=findparent(u);
       int y=findparent(v);
       if(x == y)return ;
       if(rank[x] < rank[y]){
           parent[x]=y;
       }
       else if(rank[x]>rank[y]){
           parent[y]=x;
       }
       else{
           parent[x]=y;
           rank[y]++;
       }
       
   }
   void unionfindsize(int u,int v){
       
       int x=findparent(u);
       int y=findparent(v);
       
       if(x == y) return ;
       
       if(size[x]<size[y]){
           parent[x]=y;
           size[y]+=size[x];
       }
       else if(size[x]>size[y]){
           parent[y]=x;
           size[x]+=size[y];
       }
       else{
           parent[y]=x;
           size[x]+=size[y];
       }
   }
};
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    DisjointSet ds(V);
	    
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	           if(i<it){
	               if(ds.findparent(i) == ds.findparent(it)){
	                   return true;
	               }
	           }
	           ds.unionfindrank(i,it);
	        }
	    }
	    return false;
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