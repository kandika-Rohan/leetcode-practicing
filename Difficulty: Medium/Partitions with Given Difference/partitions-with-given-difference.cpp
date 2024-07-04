//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  const int mod=1e9+7;
  int f(int ind, int target, vector<int>& arr,vector<vector<int>>&dp) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0) {
            return 2; // Corrected: If target is 0 and the first element is 0, there are 2 ways (including/excluding the 0)
        }
        if (target == 0 || target == arr[0]) { // Corrected: Check if target is 0 or if the target is the first element
            return 1;
        }
        return 0;
    }
    if(dp[ind][target] != -1){
        return dp[ind][target];
    }
    int nottake = f(ind - 1, target, arr,dp);
    int take = 0;
    if (target >= arr[ind]) {
        take = f(ind - 1, target - arr[ind], arr,dp); // Corrected: Subtract the current element from target
    }
    return dp[ind][target]=(take + nottake)%mod;
}

int countPartitions(int n, int d, vector<int>& arr) {
    int totalsum = accumulate(arr.begin(), arr.end(), 0);
    
    if ((totalsum - d) < 0 || (totalsum - d) % 2 != 0) { // Corrected: Check for invalid partition cases
        return 0;
    }
    
    int s = (totalsum - d) / 2;
    vector<vector<int>>dp(n,vector<int>(s+1,-1));
    return f(n - 1, s, arr,dp);
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends