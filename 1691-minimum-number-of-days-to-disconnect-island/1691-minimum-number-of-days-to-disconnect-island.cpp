class Solution {
private:
    vector<int> X = {-1,0,1,0};
    vector<int> Y = {0,1,0,-1};
    bool isBoundary(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> & vis){
        vis[i][j] = true;
        for(int k=0; k<4;k++){
            int ii=i+X[k];
            int jj=j+Y[k];
            if(isBoundary(ii,jj,grid.size(),grid[0].size()) 
               && grid[ii][jj] == 1 && !vis[ii][jj]){
                dfs(ii,jj,grid,vis);
            }
        }
    }
    int getIslands(vector<vector<int>> & grid){
        int n=grid.size(),m=grid[0].size(),cnt=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        if(getIslands(grid) != 1) return 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(getIslands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};