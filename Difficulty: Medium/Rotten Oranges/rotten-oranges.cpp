//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<int,pair<int,int>>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 2){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        int ans=0;
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            
            auto it=q.front();
            q.pop();
            
            int steps=it.first;
            int row=it.second.first;
            int col=it.second.second;
            ans=max(ans,steps);
            for(int k=0;k<4;k++){
                int nrow=row+delrow[k];
                int ncol=col+delcol[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 
                && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 1){
                    vis[nrow][ncol]=1;
                    q.push({steps+1,{nrow,ncol}});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends