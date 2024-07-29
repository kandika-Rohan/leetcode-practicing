class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&mat,int delrow[],int delcol[],int n,int m){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow < n && ncol >=0 && ncol <m && mat[nrow][ncol] == 1
            && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,mat,delrow,delcol,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>mat=grid;
        vector<vector<int>>vis(n,vector<int>(m,0));

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<m;i++){
            if(!vis[0][i] && mat[0][i] == 1){
                dfs(0,i,vis,mat,delrow,delcol,n,m);
            }
            if(!vis[n-1][i] && mat[n-1][i] == 1){
                dfs(n-1,i,vis,mat,delrow,delcol,n,m);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0] == 1){
                dfs(i,0,vis,mat,delrow,delcol,n,m);
            }
            if(!vis[i][m-1] && mat[i][m-1] == 1){
                dfs(i,m-1,vis,mat,delrow,delcol,n,m);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] ==1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};