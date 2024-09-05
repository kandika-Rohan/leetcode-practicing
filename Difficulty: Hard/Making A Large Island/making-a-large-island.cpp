//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DisjointSet {
private:
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void uniteBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV) return;
        if (size[rootU] < size[rootV]) {
            size[rootV] += size[rootU];
            parent[rootU] = rootV;
        } else {
            size[rootU] += size[rootV];
            parent[rootV] = rootU;
        }
    }

    int getSize(int x) {
        return size[findParent(x)];
    }
};

class Solution
{
private:
    bool isValid(int i,int j,int n){
        if(i>=0 && i<n && j>=0 && j<n){
            return true;
        }
        return false;
    }
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        //making the connected componentes;
        int n=grid.size();
        
        
        DisjointSet ds(n*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0)continue;
                
                for(int k=0;k<4;k++){
                    int nrow=i+delrow[k];
                    int ncol=j+delcol[k];
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol] == 1){
                        int node=i*n+j;
                        int adjnode=nrow*n+ncol;
                        
                        ds.uniteBySize(node,adjnode);
                    }
                }
            }
        }
        
        //know altering the 0 and checking weather it is making the larger
        //island
        
        int maxi=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == 1)continue;
                
                set<int>st;
                
                for(int k=0;k<4;k++){
                    int nrow=i+delrow[k];
                    int ncol=j+delcol[k];
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol] == 1){
                        int adjnode=nrow*n+ncol;
                        st.insert(ds.findParent(adjnode));
                    }
                }
                int total=0;
                for(auto it:st){
                    total+=ds.getSize(it);
                }
                maxi=max(maxi,total+1);
            }
        }
        
        for(int i=0;i<n*n;i++){
            maxi=max(maxi,ds.getSize(i));
        }
        
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends