//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum without selecting adjacent elements

	int f(int i, vector<int>& arr, vector<int>& dp) {
	    // Base cases
	    if (i == 0) {
	        return arr[i];
	    }
	    if (i < 0) {
	        return 0;
	    }
	    
	    if (dp[i] != -1) return dp[i];
	    
	    // Recurrence: choose to either take or not take the current element
	    int notTake = f(i - 1, arr, dp);
	    int take = arr[i] + f(i - 2, arr, dp);
	    
	    return dp[i] = max(take, notTake);
	}

	int findMaxSum(vector<int>& arr, int n) {
	    // Handle edge case for single element
	    if (n == 1) {
	        return arr[0];
	    }
	    
	    vector<int> dp(n, -1);
	    return f(n - 1, arr, dp);
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends