//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        
        int destrow=destination.first;
        int destcol=destination.second;
        
        
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int srcrow=source.first;
        int srccol=source.second;
        
        
        q.push({0,{srcrow,srccol}});
        vis[srcrow][srccol]=1;
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty()){
            
            auto it=q.front();
            
            q.pop();
            
            int steps=it.first;
            
            int row=it.second.first;
            
            int col=it.second.second;
            
            // cout<<row<<" "<<col<<endl;
            if(row == destrow && col == destcol){
                return steps;
            }
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n &&
                ncol>=0 && ncol < m && !vis[nrow][ncol] 
                && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({steps+1,{nrow,ncol}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends