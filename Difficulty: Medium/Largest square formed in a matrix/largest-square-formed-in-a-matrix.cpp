//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
 vector<vector<int>> dp(n, vector<int>(m, 0));
    
    int maxi = 0;

    // Initialize the first row and first column of dp table
    for (int i = 0; i < n; ++i) {
        dp[i][0] = mat[i][0];
        maxi = max(maxi, dp[i][0]);
    }
    for (int j = 0; j < m; ++j) {
        dp[0][j] = mat[0][j];
        maxi = max(maxi, dp[0][j]);
    }
    
    // Fill the dp table
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (mat[i][j] == 1) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                maxi = max(maxi, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
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
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends