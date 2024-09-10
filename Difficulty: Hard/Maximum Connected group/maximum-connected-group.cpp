//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int compsize(int x){
        return size[findUPar(x)];
    }
};
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int maxi=0;
        DisjointSet ds(n*n);
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0)continue;
                if(grid[i][j] == 1){
                    for(int k=0;k<4;k++){
                        int nrow=i+delrow[k];
                        int ncol=j+delcol[k];
                        if(nrow >=0 && nrow < n && ncol >=0 
                        && ncol <n && grid[nrow][ncol] == 1){
                            int node=i*n+j;
                            int adjnode=nrow*n+ncol;
                            if(ds.findUPar(node) != ds.findUPar(adjnode)){
                                ds.unionBySize(node,adjnode);
                            }
                        }
                    }
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    continue;
                }
                else{
                    unordered_set<int>st;
                    
                    for(int k=0;k<4;k++){
                        int nrow=delrow[k]+i;
                        int ncol=delcol[k]+j;
                        
                        if(nrow >=0 && nrow< n && ncol >=0 
                        && ncol <n && grid[nrow][ncol]==1){
                            int adjnode=nrow*n+ncol;
                            st.insert(ds.findUPar(adjnode));
                        }
                    }
                    
                    int totalsize=0;
                    for(auto it:st){
                        totalsize+=ds.compsize(it);
                    }
                    maxi=max(totalsize+1,maxi);
                }
            }
        }
        for(int i=0;i<n*n;i++){
            maxi=max(maxi,ds.compsize(i));
        }
        return maxi;
        
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends