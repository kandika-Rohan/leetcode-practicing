//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

	// #define ll long long


class Solution {
public:
    long long mod=1e9+7;
    long long countStrings(int n) {
        if (n == 1) return 2;  

        
        long long dp[n + 1][2];

       
        dp[1][0] = 1;  
        dp[1][1] = 1;  

       
        for (int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1])%mod; 
            dp[i][1] = (dp[i-1][0])%mod;               
        }

        
        return (dp[n][0] + dp[n][1])%mod;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends