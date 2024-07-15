//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int maximumPathRecursive(int r, int c, int n, vector<vector<int>>& mat,
   vector<vector<int>>& dp) {
    // Base case: If we are at the last row
    if (r == n - 1) {
        return dp[r][c]=mat[r][c];
    }
    if(dp[r][c] != -1){
        return dp[r][c];
    }
    // Recursive cases: Calculate maximum path sum starting from mat[r][c] to the bottom row
    int right = (c + 1 < n) ? maximumPathRecursive(r + 1, c + 1, n, mat,dp) : 0;
    int left = (c - 1 >= 0) ? maximumPathRecursive(r + 1, c - 1, n, mat,dp) : 0;
    int down = maximumPathRecursive(r + 1, c, n, mat,dp);
    
    // Return the maximum path sum including the current cell
    return dp[r][c]=mat[r][c] + max(down, max(right, left));
}

int maximumPath(int n, vector<vector<int>>& mat) {
    if (n == 0) return 0;
    
    int maxSum = 0;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    // Try each column in the first row as starting point and find the maximum path sum
    for (int c = 0; c < n; ++c) {
        maxSum = max(maxSum, maximumPathRecursive(0, c, n, mat,dp));
    }
    
    return maxSum;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends