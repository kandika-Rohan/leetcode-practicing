//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int f(int ind, int w, vector<int>&wt,vector<int>&val,vector<vector<int>>&dp) {
    if (ind == 0) {
        if (wt[0] <= w) {
            return val[0];
        } else {
            return 0;
        }
    }
    if(dp[ind][w] != -1){
        return dp[ind][w];
    }
    int nottake = 0 + f(ind - 1, w, wt, val,dp);
    int take = -1e9;  // Using a large negative value
    if (w >= wt[ind]) {
        take = val[ind] + f(ind - 1, w - wt[ind], wt, val,dp);
    }
    return dp[ind][w]=max(take, nottake);
}
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        
        return f(val.size()-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends