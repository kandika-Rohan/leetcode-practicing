//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int ind, int arr[], int last_ind, int n, vector<vector<int>>& dp) {
    if (ind == n) {
        return 0;
    }

    // Using last_ind + 1 to handle the -1 index
    if (dp[ind][last_ind + 1] != -1) {
        return dp[ind][last_ind + 1];
    }

    int nottake = f(ind + 1, arr, last_ind, n, dp);
    int take = 0;
    if (last_ind == -1 || arr[last_ind] < arr[ind]) {
        take = arr[ind] + f(ind + 1, arr, ind, n, dp);
    }

    return dp[ind][last_ind + 1] = max(take, nottake);
}

int maxSumIS(int arr[], int n) {
    // Initializing dp array with -1, size is n x (n+1)
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, arr, -1, n, dp);
}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends