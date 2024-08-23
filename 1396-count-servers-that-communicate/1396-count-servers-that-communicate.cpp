class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>&grid,int &cnt){
        if(grid[i][j] == 1){
            cnt++;
            grid[i][j]=0;
            //making it visited
            for(int c=0;c<grid[0].size();c++){
                if(grid[i][c] == 1 )dfs(i,c,grid,cnt);
            }
            for(int r=0;r<grid.size();r++){
                if(grid[r][j] == 1)dfs(r,j,grid,cnt);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        

        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int cnt=0;
                    dfs(i,j,grid,cnt);
                    if(cnt>1)ans+=cnt;
                }
            }
        }
        return ans;
    }
};