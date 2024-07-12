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
        if(grid[source.first][source.second]==0 || grid[destination.first][destination.second]==0){
            return -1;
        }
        queue<pair<int,pair<int,int>>>q;
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        dist[source.first][source.second]=0;
        
        q.push({0,{source.first,source.second}});
        
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty()){
            
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(row==destination.first && col==destination.second){
                return distance;
            }
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow >=0 && ncol >=0 && nrow < n && ncol < m && 
                grid[nrow][ncol]==1 && distance+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=distance+1;
                    q.push({distance+1,{nrow,ncol}});
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