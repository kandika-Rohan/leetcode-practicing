//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int row,int col,int n,int m,vector<vector<int>>&ans,vector<vector<int>>&vis,
  int delrow[],int delcol[]){
      
      vis[row][col]=1;
      
      for(int i=0;i<4;i++){
          int nrow=delrow[i]+row;
          int ncol=delcol[i]+col;
          if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && ans[nrow][ncol] ==1
          && !vis[nrow][ncol]){
              dfs(nrow,ncol,n,m,ans,vis,delrow,delcol);
          }
      }
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        //i created this becuase i dont wanted to edit the original data
        vector<vector<int>>ans=grid;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        
        //this is for checking the 0th row and the n-1th row
        for(int i=0;i<m;i++){
            if(ans[0][i] == 1 && !vis[0][i]){
                dfs(0,i,n,m,ans,vis,delrow,delcol);
            }
             if(ans[n-1][i] == 1 && !vis[n-1][i]){
                dfs(n-1,i,n,m,ans,vis,delrow,delcol);
            }
        }
        //this is for checking the 0th col and the m-1th col
         for(int i=0;i<n;i++){
            if(ans[i][0] == 1 && !vis[i][0]){
                dfs(i,0,n,m,ans,vis,delrow,delcol);
            }
             if(ans[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i,m-1,n,m,ans,vis,delrow,delcol);
            }
        }
        
        int cnt=0;
        //counting leftover elements in the answer array
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && ans[i][j] ==1){
                    cnt++;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends