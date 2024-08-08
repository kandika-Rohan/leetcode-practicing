//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long f(int n,vector<long long>&dp){
        if(n == 0)return 0;
        if(n == 1){
            return 1;
        }
        if(dp[n] != -1)return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    long long countWays(int n) {
       return n/2 +1;
    }
};

//{ Driver Code Starts.
int main() {
    // taking count of testcases
    int t;
    cin >> t;

    while (t--) {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends