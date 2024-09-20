//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    long long dfs(int i, int j, int n, int k, vector<vector<int>>& arr,
                  vector<vector<vector<long long>>>& dp) {
        // Base case: If k becomes negative or we go out of bounds
        if (k < 0 || i >= n || j >= n) return 0;
        
        // Check if the result is already computed
        if (dp[i][j][k] != -1) return dp[i][j][k];

        // If we reach the bottom-right corner
        if (i == n-1 && j == n-1) {
            if (k == arr[i][j]) {
                return dp[i][j][k] = 1;
            }
            return dp[i][j][k] = 0;
        }

        // Explore moving down and right, subtracting the current cell value from k
        long long down = dfs(i+1, j, n, k - arr[i][j], arr, dp);
        long long right = dfs(i, j+1, n, k - arr[i][j], arr, dp);

        // Store and return the result for the current state
        return dp[i][j][k] = down + right;
    }

    long long numberOfPath(int n, int k, vector<vector<int>>& arr) {
        // Ensure k is non-negative and large enough
        if (k < 0) return 0;

        // Initialize the 3D dp array with size [n][n][k+1], all values set to -1
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(k + 1, -1)));

        // Start the DFS from (0, 0)
        return dfs(0, 0, n, k, arr, dp);
    }
};





//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends