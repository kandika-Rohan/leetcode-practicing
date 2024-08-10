//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.


const int MOD = 1e9 + 7;

int findCatalanHelper(int n, std::vector<int>& dp) {
    if (n <= 1) return 1;
    
    // If already computed, return the cached value
    if (dp[n] != -1) return dp[n];

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + (1LL * findCatalanHelper(i - 1, dp) * findCatalanHelper(n - i, dp)) % MOD) % MOD;
    }

    dp[n] = static_cast<int>(ans);  // Cache the computed value
    return dp[n];
}

int findCatalan(int n) {
    std::vector<int> dp(n + 1, -1);  // Initialize the dp array with -1
    return findCatalanHelper(n, dp);
}

};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends