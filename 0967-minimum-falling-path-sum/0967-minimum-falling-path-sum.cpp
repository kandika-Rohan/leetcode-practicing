class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Create a dp table with the same dimensions as the matrix
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Initialize the first row of dp with the first row of the matrix
        for (int j = 0; j < m; ++j) {
            dp[0][j] = matrix[0][j];
        }
        
        // Fill the dp table
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int up = matrix[i][j] + dp[i-1][j];
                int leftDiag = (j > 0) ? matrix[i][j] + dp[i-1][j-1] : 1e9;
                int rightDiag = (j < m-1) ? matrix[i][j] + dp[i-1][j+1] : 1e9;
                
                dp[i][j] = min({up, leftDiag, rightDiag});
            }
        }
        
        // Find the minimum value in the last row of the dp table
        int mini = dp[n-1][0];
        for (int j = 1; j < m; ++j) {
            mini = min(mini, dp[n-1][j]);
        }
        
        return mini;
    }
};
