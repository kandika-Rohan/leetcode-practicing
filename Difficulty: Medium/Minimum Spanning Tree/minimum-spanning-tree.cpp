//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Dsu{
    private:
       vector<int>parent,size,rank;
    public:
       Dsu(int n){
           parent.resize(n+1);
           size.resize(n+1,1);
           rank.resize(n+1,0);
           for(int i=0;i<=n;i++){
               parent[i]=i;
               
           }
       }
       int find(int x){
           if(parent[x] == x)return x;
           return parent[x]=find(parent[x]);
       }
       
       void unite(int x,int y){
           int u=find(x);
           int v=find(y);
           if(u == v) return;
           
           if(size[u]<size[v]){
               size[v]+=size[u];
               parent[u]=v;
               
           }
           else if(size[u]>size[v]){
               size[u]+=size[v];
               parent[v]=u;
           }
           else{
               size[u]+=size[v];
               parent[v]=u;
           }
       }
       void uniteByRank(int x,int y){
           
           int u=find(x);
           int v=find(y);
           if(u == v) return;
           
           if(rank[u]<rank[v]){
               parent[u]=v;
           }
           else if(rank[u]>rank[v]){
               parent[v]=u;
           }
           else{
               parent[v]=u;
               rank[u]++;
           }
       }
       
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>>adjlist;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u=i;
                int v=it[0];
                int wt=it[1];
                adjlist.push_back({wt,{u,v}});
                
            }
        }
        
        sort(adjlist.begin(),adjlist.end());
        Dsu ds(V);
        
        int ans=0;
        
      for(auto it:adjlist){
          int wt=it.first;
          int u=it.second.first;
          int v=it.second.second;
          if(ds.find(u) == ds.find(v)){
                    continue;
                }
                else{
                    ans+=wt;
                    ds.unite(u,v);
                }
      }
        
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends