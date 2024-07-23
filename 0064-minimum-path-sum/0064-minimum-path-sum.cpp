class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid){
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(i<0 || j< 0){
            return INT_MAX;
        }
        int top=f(i-1,j,grid);
        int left=f(i,j-1,grid);
        return min(left,top)+grid[i][j];

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
       for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[0][0];
                } else {
                    int up = INT_MAX, left = INT_MAX;
                    if (i > 0) {
                        up = dp[i - 1][j] + grid[i][j];
                    }
                    if (j > 0) {
                        left = dp[i][j - 1] + grid[i][j];
                    }
                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[n - 1][m - 1];
    }
};