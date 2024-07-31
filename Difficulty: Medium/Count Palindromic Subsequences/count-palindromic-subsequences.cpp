//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long int f(int i, int j, string& str, vector<vector<long long int>>& dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (str[i] == str[j]) {
            dp[i][j] = (1 + f(i + 1, j, str, dp) + f(i, j - 1, str, dp)) % MOD;
        } else {
            dp[i][j] = (f(i + 1, j, str, dp) + f(i, j - 1, str, dp) - f(i + 1, j - 1, str, dp) + MOD) % MOD;
        }
        
        return dp[i][j];
    }
    
    long long int countPS(string str) {
        int n = str.size();
        vector<vector<long long int>> dp(n, vector<long long int>(n, -1));
        return f(0, n - 1, str, dp);
    }
};



//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends