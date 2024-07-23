class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==0 && j== 0){
            return 1;
        }
        if(i<0 || i>m || j<0 || j>n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up=f(i-1,j,m,n,dp);
        int left=f(i,j-1,m,n,dp);
        return dp[i][j]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}
};