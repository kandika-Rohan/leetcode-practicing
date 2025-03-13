//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    
    int f(int i, int j, vector<vector<int>>& matrix, int n, int m, 
    vector<vector<int>>& dp) {
        
        if (dp[i][j] != -1) return dp[i][j]; 

        int count = 1;  
        
        for (int k = 0; k < 4; k++) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && matrix[nrow][ncol] > matrix[i][j]) {
                count = max(count, 1 + f(nrow, ncol, matrix, n, m, dp));
            }
        }
        
        return dp[i][j] = count;  
    }

    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));  
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, f(i, j, matrix, n, m, dp));
            }
        }
        
        return maxi;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends