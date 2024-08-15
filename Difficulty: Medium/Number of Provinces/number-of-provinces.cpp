//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    vector<int>parent,size,rank;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findparent(int x){
        if(parent[x] == x)return x;
        return parent[x]=findparent(parent[x]);
    }
    
    void unionFindRank(int u,int v){
        int x=findparent(u);
        int y=findparent(v);
        
        if(x == y)return;
        
        if(rank[x]<rank[y]){
            parent[x]=y;
            
        }
        else if(rank[x]>rank[y]){
            parent[y]=x;
        }
        else{
            parent[y]=x;
            rank[x]++;
        }
    }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        vector<int>adjlist[V];
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        
        
        DisjointSet ds(V);
        
        
        for(int i=0;i<V;i++){
            for(auto it:adjlist[i]){
                if(i<it){
                    if(ds.findparent(i) == ds.findparent(it)){
                        continue;
                    }
                }
                
                ds.unionFindRank(i,it);
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++){
            if(i == ds.findparent(i)){
                cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends