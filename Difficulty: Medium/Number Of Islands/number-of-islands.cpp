//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    
    void uniteByRank(int u,int v){
        int x=findparent(u);
        int y=findparent(v);
        if( x == y)return;
        
        if(rank[x] <rank[y]){
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
    
    void uniteBySize(int u,int v){
        int x=findparent(u);
        int y=findparent(v);
        
        if(x == y)return;
        
        if(size[x] < size[y]){
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
class Solution {
  bool isvalid(int i,int j,int n,int m){
      return (i>=0 && j>=0 && i<n && j<m);
  }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        DisjointSet ds(n*m);
        
        int vis[n][m];
        memset(vis,0,sizeof vis);
        
        
        int grid[n][m];
        memset(grid,0,sizeof vis);
        
        vector<int>ans;
        
        int cnt=0;
        
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            
            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
                if(isvalid(nrow,ncol,n,m)){
                    if(vis[nrow][ncol] == 1){
                        int node=row*m+col;
                        int adjnode=nrow*m+ncol;
                        
                        if(ds.findparent(node) != ds.findparent(adjnode)){
                            cnt--;
                            ds.uniteBySize(node,adjnode);
                        }
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends